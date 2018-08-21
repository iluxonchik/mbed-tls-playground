#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_time       time
#define mbedtls_time_t     time_t
#define mbedtls_fprintf    fprintf
#define mbedtls_printf     printf
#endif

#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_CERTS_C) ||    \
    !defined(MBEDTLS_ENTROPY_C) || !defined(MBEDTLS_SSL_TLS_C) || \
    !defined(MBEDTLS_SSL_SRV_C) || !defined(MBEDTLS_NET_C) ||     \
    !defined(MBEDTLS_RSA_C) || !defined(MBEDTLS_CTR_DRBG_C) ||    \
    !defined(MBEDTLS_X509_CRT_PARSE_C) || !defined(MBEDTLS_FS_IO) || \
    !defined(MBEDTLS_PEM_PARSE_C)
int main( void )
{
    mbedtls_printf("MBEDTLS_BIGNUM_C and/or MBEDTLS_CERTS_C and/or MBEDTLS_ENTROPY_C "
           "and/or MBEDTLS_SSL_TLS_C and/or MBEDTLS_SSL_SRV_C and/or "
           "MBEDTLS_NET_C and/or MBEDTLS_RSA_C and/or "
           "MBEDTLS_CTR_DRBG_C and/or MBEDTLS_X509_CRT_PARSE_C "
           "and/or MBEDTLS_PEM_PARSE_C not defined.\n");
    return( 0 );
}
#else

#include <stdlib.h>
#include <string.h>
#include <mbedtls/dhm.h>

#if defined(_WIN32)
#include <windows.h>
#endif

#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"
#include "mbedtls/x509.h"
#include "mbedtls/ssl.h"
#include "mbedtls/net_sockets.h"
#include "mbedtls/error.h"
#include "mbedtls/debug.h"

#if defined(MBEDTLS_SSL_CACHE_C)
#include "mbedtls/ssl_cache.h"
#endif

#include "mbedtls/security_level.h"
//#include "mbedtls/debug.h"


#define SERVER_MSG "pong"

#define DEBUG_LEVEL 3

static void my_debug( void *ctx, int level,
                      const char *file, int line,
                      const char *str )
{
    ((void) level);

    mbedtls_fprintf( (FILE *) ctx, "%s:%04d: %s", file, line, str );
    fflush(  (FILE *) ctx  );
}

// TODO: refactor into a new file
// Setup PSK Stuff

typedef struct _psk_entry psk_entry;

struct _psk_entry
{
    const char *name;
    size_t key_len;
    unsigned char key[MBEDTLS_PSK_MAX_LEN];
    psk_entry *next;
};

unsigned char *generate_random_bytes(size_t send);

/*
 * PSK callback. For now, this method completely ignores the
 * PSK identity name and uses the same key for any PSK id you pass.
 *
 * Later, this should handle different PSK ids, corresponding to
 * different PSK sizes, for example.
 */
int psk_callback( void *p_info, mbedtls_ssl_context *ssl,
                  const unsigned char *name, size_t name_len )
{
    // in a normal setting, you would get the PSK value and length from
    // the p_info structure.
    mbedtls_printf("psk_callback()\n");
    return( mbedtls_ssl_set_hs_psk( ssl, psk_value, sizeof(psk_value) ));
}

#define HEX2NUM( c )                    \
        if( c >= '0' && c <= '9' )      \
            c -= '0';                   \
        else if( c >= 'a' && c <= 'f' ) \
            c -= 'a' - 10;              \
        else if( c >= 'A' && c <= 'F' ) \
            c -= 'A' - 10;              \
        else                            \
            return( -1 );

/*
 * Convert a hex string to bytes.
 * Return 0 on success, -1 on error.
 */
int unhexify( unsigned char *output, const char *input, size_t *olen )
{
    unsigned char c;
    size_t j;

    *olen = strlen( input );
    if( *olen % 2 != 0 || *olen / 2 > MBEDTLS_PSK_MAX_LEN )
        return( -1 );
    *olen /= 2;

    for( j = 0; j < *olen * 2; j += 2 )
    {
        c = input[j];
        HEX2NUM( c );
        output[ j / 2 ] = c << 4;

        c = input[j + 1];
        HEX2NUM( c );
        output[ j / 2 ] |= c;
    }

    return( 0 );
}

void print_security_level() {

mbedtls_printf("---\n");
mbedtls_printf("\tUsing security level of ");

#ifdef USE_RSA_2048
   mbedtls_printf(" RSA 2048 bit and equivalent.");
#endif

#ifdef USE_RSA_7680
   mbedtls_printf(" RSA 7680 bit and equivalent.");
#endif

#ifdef USE_RSA_15360
   mbedtls_printf(" RSA 15360 bit and equivalent.");
#endif

mbedtls_printf("\n---\n");

}

#define MAGIC_END_BYTE 192

unsigned char *generate_random_bytes(size_t num_bytes) {
    if (num_bytes < 1) {
        mbedtls_printf("[!!!] Requested number of random bytes is %d. Returning null...\n", num_bytes);
        return NULL;
    } else {
        mbedtls_printf("Generating %d random bytes...\n", num_bytes);
    }

    unsigned char* rand_bytes = (unsigned char*) malloc(num_bytes * sizeof(unsigned char*));
    int rand_byte;
    for (size_t i = 0; i < num_bytes-1; i++){
        rand_byte = rand();
        rand_bytes[i] = rand_byte;
    }

    return rand_bytes;
}

int main( int argc, char** argv )
{
    char *ciphersuite_str_id;
    int ciphersuite_id;
    int custom_cipher_suite[2];
    char *ciphersuite_name;

    int ret;
    size_t len, num_bytes_written, num_bytes_read = 0;
    mbedtls_net_context listen_fd, client_fd;
    unsigned char* send_buf;
    unsigned char read_buf [1024];
    const char *pers = "ssl_server";
    char *chosen_cipher;

    size_t num_bytes_to_send = 4;

    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;
    mbedtls_x509_crt srvcert;
    mbedtls_pk_context pkey;

    unsigned char psk[MBEDTLS_PSK_MAX_LEN];
    unsigned short int is_use_psk = 0;


#if defined(MBEDTLS_SSL_CACHE_C)
    mbedtls_ssl_cache_context cache;
#endif

    mbedtls_net_init( &listen_fd );
    mbedtls_net_init( &client_fd );
    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_config_init( &conf );
#if defined(MBEDTLS_SSL_CACHE_C)
    mbedtls_ssl_cache_init( &cache );
#endif
    mbedtls_x509_crt_init( &srvcert );
    mbedtls_pk_init( &pkey );
    mbedtls_entropy_init( &entropy );
    mbedtls_ctr_drbg_init( &ctr_drbg );

#if defined(MBEDTLS_DEBUG_C)
    //mbedtls_debug_set_threshold( DEBUG_LEVEL );
#endif

    // parse arg
    if (argc < 2) {
        mbedtls_printf("[!!!] No ciphersuite argument provided\n");
        return ( -1 );
    }

    if (argc > 2) {
        // num of bytes to send provided
        num_bytes_to_send = strtol(argv[2], NULL, 10);
    }

    if (num_bytes_to_send == 0) {
        mbedtls_printf("[!!!] Cannot send less than 1 byte. Setting number of bytes to send to 1...\n");
        num_bytes_to_send = 1;
    }

    print_security_level();

    ciphersuite_str_id = argv[1];

    ciphersuite_id = strtol(ciphersuite_str_id, NULL, 10);
    custom_cipher_suite[0] = ciphersuite_id;
    custom_cipher_suite[1] = 0;
    mbedtls_printf("Chosen ciphersuite id: %d\n", custom_cipher_suite[0]);


    srand((unsigned int) time(NULL));
    // generate random bytes to send (if needed)
    if (num_bytes_to_send == 4) {
        // specifically used to profile the handshake
        mbedtls_printf("Number of bytes to send is 4. Setting to default value \"PONG\"\n");
        send_buf = "PONG";
    } else {
        send_buf = generate_random_bytes(num_bytes_to_send);
    }

    /*
    mbedtls_ssl_conf_dbg(&conf, my_debug, NULL);
    mbedtls_debug_set_threshold(DEBUG_LEVEL);
    */

    mbedtls_dhm_context dhm;
    mbedtls_dhm_init( &dhm );

    /*
     * 1. Load the certificates and private RSA key
     */
    mbedtls_printf( "\n  . Loading the server cert. and key..." );
    fflush( stdout );

    /*
     * This demonstration program uses embedded test certificates.
     * Instead, you may want to use mbedtls_x509_crt_parse_file() to read the
     * server and CA certificates, as well as mbedtls_pk_parse_keyfile().
     */
    ciphersuite_name = mbedtls_ssl_get_ciphersuite_name(ciphersuite_id);

    unsigned char* srv_crt;
    size_t srv_crt_len;
    unsigned char *srv_key;
    size_t srv_key_len;

    // Now let's decide on which certificate to use
    const char* use_cert_with_ecdh_params = "DH-";
    const char* use_cert_with_ecdh_rsa_params = "ECDH-RSA";
    const char* use_cert_with_ecdsa_sig = "ECDSA";

    const char* use_psk = "PSK";
    const char* use_rsa = "RSA"; // for RSA_PSK ciphersuites

    // load the default server cert and key values
    srv_crt = mbedtls_test_srv_crt_rsa;
    srv_crt_len = mbedtls_test_srv_crt_rsa_len;
    srv_key = mbedtls_test_srv_key_rsa;
    srv_key_len = mbedtls_test_srv_key_rsa_len;
    mbedtls_printf("\nCiphersuite Name: %s\n", ciphersuite_name);

    if (strstr(ciphersuite_name, use_cert_with_ecdh_params) != NULL){
        mbedtls_printf("[INFO] Using DH certificate\n");
        srv_crt = mbedtls_test_srv_crt_ec;
        srv_crt_len = mbedtls_test_srv_crt_ec_len;

        srv_key = mbedtls_test_srv_key_ec;
        srv_key_len = mbedtls_test_srv_key_ec_len;

        if (strstr(ciphersuite_name, use_cert_with_ecdh_rsa_params) != NULL) {
            mbedtls_printf("\t[INFO] Using ECDH_RSA certificate\n");
            srv_crt = mbedtls_test_srv_crt_ecdh_rsa;
            srv_crt_len = mbedtls_test_srv_crt_ecdh_rsa_len;

        }
    }

    // This one is here for the TLS-ECDHE-ECDSA-* cipher suites
    if (strstr(ciphersuite_name, use_cert_with_ecdsa_sig) != NULL) {
        mbedtls_printf("[INFO] Using ECDSA signed certificate (ECDH-ECDSA)\n");
        srv_crt = mbedtls_test_srv_crt_ec;
        srv_crt_len = mbedtls_test_srv_crt_ec_len;

        srv_key = mbedtls_test_srv_key_ec;
        srv_key_len = mbedtls_test_srv_key_ec_len;
    }

    if (strstr(ciphersuite_name, use_psk) != NULL) {
        is_use_psk = 1;
        int psk_len = strlen(psk_value);
        mbedtls_printf("[INFO]Using PSK\n");

        // For the case where RSA_PSK ciphersuites are used. Here, we still want to use a certificate.
        // This "if" can be refactored and put above, but I'd like to keep it here for easier readability.
        if (strstr(ciphersuite_name, use_rsa) != NULL) {
           is_use_psk = 0;
        }

        if( unhexify( psk, psk_value, &psk_len ) != 0 )
        {
            mbedtls_printf( "pre-shared key not valid hex\n" );
            goto exit;
        }

        ret = mbedtls_ssl_conf_psk( &conf, psk, psk_len, psk_identity, strlen(psk_identity));

        if( ret != 0 )
        {
            mbedtls_printf( "  failed\n  mbedtls_ssl_conf_psk returned -0x%04X\n\n", - ret );
            goto exit;
        }

        mbedtls_ssl_conf_psk_cb( &conf, psk_callback, NULL );
    }

    if (is_use_psk == 0) {

        ret = mbedtls_x509_crt_parse(&srvcert, (const unsigned char *) srv_crt,
                                     srv_crt_len);
        if (ret != 0) {
            mbedtls_printf(" failed\n  !  mbedtls_x509_crt_parse #1 returned %d\n\n", ret);
            goto exit;
        }

        ret = mbedtls_x509_crt_parse(&srvcert, (const unsigned char *) mbedtls_test_cas_pem,
                                     mbedtls_test_cas_pem_len);
        if (ret != 0) {
            mbedtls_printf(" failed\n  !  mbedtls_x509_crt_parse #2 returned %d\n\n", ret);
            goto exit;
        }

        // INFO: mbedtls_test_srv_key is defined in certs.c. It's literally a defined string
        ret = mbedtls_pk_parse_key(&pkey, (const unsigned char *) srv_key,
                                   srv_key_len, NULL, 0);
        if (ret != 0) {
            mbedtls_printf(" failed\n  !  mbedtls_pk_parse_key returned %d\n\n", ret);
            goto exit;
        }

        mbedtls_printf(" ok\n");
        mbedtls_printf("\n\n%s\n\n", srv_crt);

    } else {

        mbedtls_printf("\tSkipping certificate loading because a PSK ciphersuite is in use...\n");
    }

    /*
     * 2. Setup the listening TCP socket
     */
    mbedtls_printf( "  . Bind on https://localhost:4433/ ..." );
    fflush( stdout );

    if( ( ret = mbedtls_net_bind( &listen_fd, NULL, "4433", MBEDTLS_NET_PROTO_TCP ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_net_bind returned %d\n\n", ret );
        goto exit;
    }

    mbedtls_printf( " ok\n" );

    /*
     * 3. Seed the RNG
     */
    mbedtls_printf( "  . Seeding the random number generator..." );
    fflush( stdout );

    if( ( ret = mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func, &entropy,
                                       (const unsigned char *) pers,
                                       strlen( pers ) ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret );
        goto exit;
    }

    mbedtls_printf( " ok\n" );

    /*
     * 4. Setup stuff
     */
    mbedtls_printf( "  . Setting up the SSL data...." );
    fflush( stdout );

    if( ( ret = mbedtls_ssl_config_defaults( &conf,
                                             MBEDTLS_SSL_IS_SERVER,
                                             MBEDTLS_SSL_TRANSPORT_STREAM,
                                             MBEDTLS_SSL_PRESET_DEFAULT ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ssl_config_defaults returned %d\n\n", ret );
        goto exit;
    }

    // Enable RC4 cipher support
    mbedtls_ssl_conf_arc4_support(&conf, MBEDTLS_SSL_ARC4_ENABLED);
    mbedtls_printf(" ok\n");

    mbedtls_printf( "  . Setting up custom ciphersuite..." );
    fflush( stdout );

    mbedtls_ssl_conf_ciphersuites(&conf, custom_cipher_suite);

    mbedtls_printf(" ok\n");

    mbedtls_ssl_conf_rng( &conf, mbedtls_ctr_drbg_random, &ctr_drbg );
    mbedtls_ssl_conf_dbg( &conf, my_debug, stdout );

#if defined(MBEDTLS_SSL_CACHE_C)
    mbedtls_ssl_conf_session_cache( &conf, &cache,
                                    mbedtls_ssl_cache_get,
                                    mbedtls_ssl_cache_set );
#endif

    if (is_use_psk == 0) {
        mbedtls_ssl_conf_ca_chain(&conf, srvcert.next, NULL);
        if ((ret = mbedtls_ssl_conf_own_cert(&conf, &srvcert, &pkey)) != 0) {
            mbedtls_printf(" failed\n  ! mbedtls_ssl_conf_own_cert returned %d\n\n", ret);
            goto exit;
        }
    } else {
        mbedtls_printf("\tSkipping CA chain conf, because a PSK ciphersuite is in use...\n");
    }

    if( ( ret = mbedtls_ssl_setup( &ssl, &conf ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ssl_setup returned %d\n\n", ret );
        goto exit;
    }

    reset:
#ifdef MBEDTLS_ERROR_C
    if( ret != 0 ) {
        char error_buf[100];
        mbedtls_strerror(ret, error_buf, 100);
        mbedtls_printf("Last error was: %d - %s\n\n", ret, error_buf);
        mbedtls_printf("The error might be caused by the fact that you're using incompatible certificate/ciphersuite types. For example, you might be trying to use a DSA ciphersuite when using an RSA certificate.");
        goto exit_no_msg; // let's end on err here
    }
#endif

    mbedtls_net_free( &client_fd );

    mbedtls_ssl_session_reset( &ssl );

    /*
     * 3. Wait until a client connects
     */
    mbedtls_printf( "  . Waiting for a remote connection ..." );
    fflush( stdout );

    if( ( ret = mbedtls_net_accept( &listen_fd, &client_fd,
                                    NULL, 0, NULL ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_net_accept returned %d\n\n", ret );
        goto exit;
    }

    mbedtls_ssl_set_bio( &ssl, &client_fd, mbedtls_net_send, mbedtls_net_recv, NULL );

    mbedtls_printf( " ok\n" );

    // NOTE: this *MUST* be here, otherwise the default DH param will be used (order of the handshake set up)
    // TODO: mbedtls_dhm_free(&dhm); on exit
    ret = mbedtls_dhm_parse_dhm(&dhm, dhm_params, dhm_params_len);
    if (ret != 0) {
        mbedtls_printf(" ERROR parsing DH parameters.\n");
        goto exit;
    }

    ret = mbedtls_ssl_conf_dh_param_ctx( &conf, &dhm );

    if( ret != 0 )
    {
        mbedtls_printf( "  failed\n  mbedtls_ssl_conf_dh_param returned -0x%04X\n\n", - ret );
        goto exit;
    }

    /*
     * 5. Handshake
     */
    mbedtls_printf( "  . Performing the SSL/TLS handshake..." );
    fflush( stdout );

    while( ( ret = mbedtls_ssl_handshake( &ssl ) ) != 0 )
    {
        if( ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE )
        {
            mbedtls_printf( " failed\n  ! mbedtls_ssl_handshake returned %d\n\n", ret );
            goto reset;
        }
    }

    mbedtls_printf( " ok\n" );
    chosen_cipher = mbedtls_ssl_get_ciphersuite( &ssl );
    mbedtls_printf("   Negotiated Ciphersuite: %s\n", chosen_cipher);

    /*
     * 6. Read the HTTP Request
     */
    mbedtls_printf( "  < Read from client:\n" );
    fflush( stdout ) - 1;
    len = sizeof( read_buf );
    memset( read_buf, 0, sizeof( read_buf ) );
    int terminated = 0;
    unsigned char last_read_byte;

    do
    {

        ret = mbedtls_ssl_read( &ssl, read_buf, len );

        if( ret == MBEDTLS_ERR_SSL_WANT_READ || ret == MBEDTLS_ERR_SSL_WANT_WRITE ){
            mbedtls_printf("WANT READ or WANT WRITE\n");
            continue;
        }

        if( ret == MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY ){
            mbedtls_printf("CLOSE NOTIFY \n");
            break;
        }

        if( ret < 0 )
        {
            mbedtls_printf( "failed\n  ! mbedtls_ssl_read returned %d\n\n", ret );
            break;
        }

        if( ret == 0 )
        {
            mbedtls_printf( "\n\nEOF\n\n" );
            break;
        }

        num_bytes_read += ret;
        last_read_byte = read_buf[ret - 1];

        if (last_read_byte == (unsigned char) MAGIC_END_BYTE) {
            terminated = 1;
        }
    }
    while( terminated == 0 );

    mbedtls_printf( " %d bytes read:\n", num_bytes_read);
    //mbedtls_printf( " %d bytes read:\n%s\n", len, (char *) read_buf );
    /*
     * 7. Write the 200 Response
     */
    mbedtls_printf( "  > Write to client:\n" );
    fflush( stdout );


    len = num_bytes_to_send;
    ret = 0;

    while( ret = mbedtls_ssl_write( &ssl, send_buf + ret, len) )
    {

        if( ret == MBEDTLS_ERR_NET_CONN_RESET )
        {
            mbedtls_printf( " failed\n  ! peer closed the connection\n\n" );
            goto reset;
        }

        num_bytes_written += ret;

        if (ret == len) {
            break;
        }

        len -= ret ;
    }

    //mbedtls_printf( " %d bytes written\n%s\n", num_bytes_written, (char *) send_buf );
    mbedtls_printf( " %d bytes written\n", num_bytes_written);

    mbedtls_printf( "  . Closing the connection..." );

    while( ( ret = mbedtls_ssl_close_notify( &ssl ) ) < 0 )
    {
        if( ret != MBEDTLS_ERR_SSL_WANT_READ &&
            ret != MBEDTLS_ERR_SSL_WANT_WRITE )
        {
            mbedtls_printf( " failed\n  ! mbedtls_ssl_close_notify returned %d\n\n", ret );
            goto reset;
        }
    }

    mbedtls_printf( " ok\n" );

    ret = 0;
    mbedtls_printf("Terminating server...\n");
    goto exit;

    exit:

#ifdef MBEDTLS_ERROR_C
    if( ret != 0 )
    {
        char error_buf[100];
        mbedtls_strerror( ret, error_buf, 100 );
        mbedtls_printf("Last error was: %d - %s\n\n", ret, error_buf );
    }
#endif

    exit_no_msg:

    mbedtls_net_free( &client_fd );
    mbedtls_net_free( &listen_fd );

    mbedtls_x509_crt_free( &srvcert );
    mbedtls_pk_free( &pkey );
    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_config_free( &conf );
#if defined(MBEDTLS_SSL_CACHE_C)
    mbedtls_ssl_cache_free( &cache );
#endif
    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );

#if defined(_WIN32)
    mbedtls_printf( "  Press Enter to exit this program.\n" );
    fflush( stdout ); getchar();
#endif

    return( ret );
}


#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_CERTS_C && MBEDTLS_ENTROPY_C &&
          MBEDTLS_SSL_TLS_C && MBEDTLS_SSL_SRV_C && MBEDTLS_NET_C &&
          MBEDTLS_RSA_C && MBEDTLS_CTR_DRBG_C && MBEDTLS_X509_CRT_PARSE_C
          && MBEDTLS_FS_IO && MBEDTLS_PEM_PARSE_C */
