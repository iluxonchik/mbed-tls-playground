/*
 *  Elliptic curve Diffie-Hellman
 *
 *  Copyright (C) 2006-2015, ARM Limited, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */

/*
 * References:
 *
 * SEC1 http://www.secg.org/index.php?action=secg,docs_secg
 * RFC 4492
 */

/* PAPI Config BEGIN */
#include <papi.h>

#include "mbedtls/papi_globals.h"
extern int papi_retval;

// ECDH generate shared secret
extern long long mbedtls_ecdh_gen_shared_proctime = 0;
extern long long mbedtls_ecdh_gen_shared_cycles_virt = 0;

// ECDH generate keypair
extern long long mbedtls_ecdh_gen_keypair_proctime = 0;
extern long long mbedtls_ecdh_gen_keypair_cycles_virt = 0;

/* PAPI Config END */

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_ECDH_C)

#include "mbedtls/ecdh.h"

#include <string.h>
#include <mbedtls/platform.h>
#include <mbedtls/bn_mul.h>

#if !defined(MBEDTLS_ECDH_GEN_PUBLIC_ALT)
/*
 * Generate public key: simple wrapper around mbedtls_ecp_gen_keypair
 */
int mbedtls_ecdh_gen_public( mbedtls_ecp_group *grp, mbedtls_mpi *d, mbedtls_ecp_point *Q,
                     int (*f_rng)(void *, unsigned char *, size_t),
                     void *p_rng )
{

    //mbedtls_printf("\n\n****\nGenerating Keypair\n****\n\n");

    long long start_cycles_virt, end_cycles_virt, start_usec_virt, end_usec_virt;

    papi_retval = PAPI_library_init(PAPI_VER_CURRENT);

    if (papi_retval != PAPI_VER_CURRENT && papi_retval > 0) {
        mbedtls_fprintf(stderr, "PAPI library version mismatch!\n");
        exit(1);
    }

    if (papi_retval < 0) {
        mbedtls_fprintf(stderr, "Initialization error!\n");
        exit(1);
    }

    /* Gets the starting time in clock cycles */
    start_cycles_virt = PAPI_get_virt_cyc();

    /* Gets the starting time in microseconds */
    start_usec_virt = PAPI_get_virt_usec();

    int ret =  mbedtls_ecp_gen_keypair( grp, d, Q, f_rng, p_rng );

    /* Gets the ending time in clock cycles */
    end_cycles_virt = PAPI_get_virt_cyc();

    /* Gets the ending time in microseconds */
    end_usec_virt = PAPI_get_virt_usec();

    mbedtls_ecdh_gen_keypair_proctime += (end_usec_virt - start_usec_virt);
    mbedtls_ecdh_gen_keypair_cycles_virt += (end_cycles_virt - start_cycles_virt);
    return ret;
}
#endif /* MBEDTLS_ECDH_GEN_PUBLIC_ALT */

#if !defined(MBEDTLS_ECDH_COMPUTE_SHARED_ALT)
/*
 * Compute shared secret (SEC1 3.3.1)
 */
int mbedtls_ecdh_compute_shared( mbedtls_ecp_group *grp, mbedtls_mpi *z,
                         const mbedtls_ecp_point *Q, const mbedtls_mpi *d,
                         int (*f_rng)(void *, unsigned char *, size_t),
                         void *p_rng )
{

    int ret;
    mbedtls_ecp_point P;

    // debug prints

    mbedtls_printf("\n\n\n\n\nGroup info:\n");
    mbedtls_printf("\tid: %d\n", grp->id);
    mbedtls_printf("\td (number of limbs): %d\n", d->n);
    mbedtls_printf("\n\n\n\n\n");


    mbedtls_ecp_point_init( &P );

    /*
     * Make sure Q is a valid pubkey before using it
     */
    MBEDTLS_MPI_CHK( mbedtls_ecp_check_pubkey( grp, Q ) );

    MBEDTLS_MPI_CHK( mbedtls_ecp_mul( grp, &P, d, Q, f_rng, p_rng ) );

    if( mbedtls_ecp_is_zero( &P ) )
    {
        ret = MBEDTLS_ERR_ECP_BAD_INPUT_DATA;
        goto cleanup;
    }

    MBEDTLS_MPI_CHK( mbedtls_mpi_copy( z, &P.X ) );

cleanup:
    mbedtls_ecp_point_free( &P );
    return( ret );
}
#endif /* MBEDTLS_ECDH_COMPUTE_SHARED_ALT */

/*
 * Initialize context
 */
void mbedtls_ecdh_init( mbedtls_ecdh_context *ctx )
{
    memset( ctx, 0, sizeof( mbedtls_ecdh_context ) );
}

/*
 * Free context
 */
void mbedtls_ecdh_free( mbedtls_ecdh_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_ecp_group_free( &ctx->grp );
    mbedtls_ecp_point_free( &ctx->Q   );
    mbedtls_ecp_point_free( &ctx->Qp  );
    mbedtls_ecp_point_free( &ctx->Vi  );
    mbedtls_ecp_point_free( &ctx->Vf  );
    mbedtls_mpi_free( &ctx->d  );
    mbedtls_mpi_free( &ctx->z  );
    mbedtls_mpi_free( &ctx->_d );
}

/*
 * Setup and write the ServerKeyExhange parameters (RFC 4492)
 *      struct {
 *          ECParameters    curve_params;
 *          ECPoint         public;
 *      } ServerECDHParams;
 */
int mbedtls_ecdh_make_params( mbedtls_ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng )
{
    int ret;
    size_t grp_len, pt_len;

    if( ctx == NULL || ctx->grp.pbits == 0 )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    if( ( ret = mbedtls_ecdh_gen_public( &ctx->grp, &ctx->d, &ctx->Q, f_rng, p_rng ) )
                != 0 )
        return( ret );

    if( ( ret = mbedtls_ecp_tls_write_group( &ctx->grp, &grp_len, buf, blen ) )
                != 0 )
        return( ret );

    buf += grp_len;
    blen -= grp_len;

    if( ( ret = mbedtls_ecp_tls_write_point( &ctx->grp, &ctx->Q, ctx->point_format,
                                     &pt_len, buf, blen ) ) != 0 )
        return( ret );

    *olen = grp_len + pt_len;
    return( 0 );
}

/*
 * Read the ServerKeyExhange parameters (RFC 4492)
 *      struct {
 *          ECParameters    curve_params;
 *          ECPoint         public;
 *      } ServerECDHParams;
 */
int mbedtls_ecdh_read_params( mbedtls_ecdh_context *ctx,
                      const unsigned char **buf, const unsigned char *end )
{
    int ret;

    if( ( ret = mbedtls_ecp_tls_read_group( &ctx->grp, buf, end - *buf ) ) != 0 )
        return( ret );

    if( ( ret = mbedtls_ecp_tls_read_point( &ctx->grp, &ctx->Qp, buf, end - *buf ) )
                != 0 )
        return( ret );

    return( 0 );
}

/*
 * Get parameters from a keypair
 */
int mbedtls_ecdh_get_params( mbedtls_ecdh_context *ctx, const mbedtls_ecp_keypair *key,
                     mbedtls_ecdh_side side )
{
    int ret;

    if( ( ret = mbedtls_ecp_group_copy( &ctx->grp, &key->grp ) ) != 0 )
        return( ret );

    /* If it's not our key, just import the public part as Qp */
    if( side == MBEDTLS_ECDH_THEIRS )
        return( mbedtls_ecp_copy( &ctx->Qp, &key->Q ) );

    /* Our key: import public (as Q) and private parts */
    if( side != MBEDTLS_ECDH_OURS )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    if( ( ret = mbedtls_ecp_copy( &ctx->Q, &key->Q ) ) != 0 ||
        ( ret = mbedtls_mpi_copy( &ctx->d, &key->d ) ) != 0 )
        return( ret );

    return( 0 );
}

/*
 * Setup and export the client public value
 */
int mbedtls_ecdh_make_public( mbedtls_ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng )
{
    int ret;

    if( ctx == NULL || ctx->grp.pbits == 0 )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    if( ( ret = mbedtls_ecdh_gen_public( &ctx->grp, &ctx->d, &ctx->Q, f_rng, p_rng ) )
                != 0 )
        return( ret );

    return mbedtls_ecp_tls_write_point( &ctx->grp, &ctx->Q, ctx->point_format,
                                olen, buf, blen );
}

/*
 * Parse and import the client's public value
 */
int mbedtls_ecdh_read_public( mbedtls_ecdh_context *ctx,
                      const unsigned char *buf, size_t blen )
{
    int ret;
    const unsigned char *p = buf;

    if( ctx == NULL )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    if( ( ret = mbedtls_ecp_tls_read_point( &ctx->grp, &ctx->Qp, &p, blen ) ) != 0 )
        return( ret );

    if( (size_t)( p - buf ) != blen )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    return( 0 );
}

/*
 * Derive and export the shared secret
 */
int mbedtls_ecdh_calc_secret( mbedtls_ecdh_context *ctx, size_t *olen,
                      unsigned char *buf, size_t blen,
                      int (*f_rng)(void *, unsigned char *, size_t),
                      void *p_rng )
{
    /*
    mbedtls_printf("\n\n***Generating Shared Secret**\n\n");
    mbedtls_printf("\tZ (shared secret): %d", ctx->z);

    // and this is how we print an mbedtls_mpi
    char bfr [8000];
    size_t ret_len;
    if (mbedtls_mpi_write_string(&ctx->d, 10, bfr, 8000, &ret_len) != 0) {
        mbedtls_printf("\nERROR reading MPI\n");
    }
    mbedtls_printf("\td (private key): %s", bfr);
   */

    long long start_cycles_virt, end_cycles_virt, start_usec_virt, end_usec_virt;

    papi_retval = PAPI_library_init(PAPI_VER_CURRENT);

    if (papi_retval != PAPI_VER_CURRENT && papi_retval > 0) {
        mbedtls_fprintf(stderr, "PAPI library version mismatch!\n");
        exit(1);
    }

    if (papi_retval < 0) {
        mbedtls_fprintf(stderr, "Initialization error!\n");
        exit(1);
    }

    /* Gets the ending time in clock cycles */
    start_cycles_virt = PAPI_get_virt_cyc();

    /* Gets the ending time in microseconds */
    start_usec_virt = PAPI_get_virt_usec();

    if( ctx == NULL )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    int ret;

    if( ( ret = mbedtls_ecdh_compute_shared( &ctx->grp, &ctx->z, &ctx->Qp, &ctx->d,
                                     f_rng, p_rng ) ) != 0 )
    {
        return( ret );
    }

     /* Gets the ending time in clock cycles */
    end_cycles_virt = PAPI_get_virt_cyc();

    /* Gets the ending time in microseconds */
    end_usec_virt = PAPI_get_virt_usec();

    mbedtls_ecdh_gen_shared_proctime += (end_usec_virt - start_usec_virt);
    mbedtls_ecdh_gen_shared_cycles_virt += (end_cycles_virt - start_cycles_virt);

    if( mbedtls_mpi_size( &ctx->z ) > blen )
        return( MBEDTLS_ERR_ECP_BAD_INPUT_DATA );

    *olen = ctx->grp.pbits / 8 + ( ( ctx->grp.pbits % 8 ) != 0 );
    ret = mbedtls_mpi_write_binary( &ctx->z, buf, *olen );

    return ret;
}

#endif /* MBEDTLS_ECDH_C */
