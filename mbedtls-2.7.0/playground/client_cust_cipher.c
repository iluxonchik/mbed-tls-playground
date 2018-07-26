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

#if !defined(MBEDTLS_BIGNUM_C) || !defined(MBEDTLS_ENTROPY_C) ||  \
    !defined(MBEDTLS_SSL_TLS_C) || !defined(MBEDTLS_SSL_CLI_C) || \
    !defined(MBEDTLS_NET_C) || !defined(MBEDTLS_RSA_C) ||         \
    !defined(MBEDTLS_CERTS_C) || !defined(MBEDTLS_PEM_PARSE_C) || \
    !defined(MBEDTLS_CTR_DRBG_C) || !defined(MBEDTLS_X509_CRT_PARSE_C)
int main( void )
{
    mbedtls_printf("MBEDTLS_BIGNUM_C and/or MBEDTLS_ENTROPY_C and/or "
           "MBEDTLS_SSL_TLS_C and/or MBEDTLS_SSL_CLI_C and/or "
           "MBEDTLS_NET_C and/or MBEDTLS_RSA_C and/or "
           "MBEDTLS_CTR_DRBG_C and/or MBEDTLS_X509_CRT_PARSE_C "
           "not defined.\n");
    return( 0 );
}
#else

#include "mbedtls/net_sockets.h"
#include "mbedtls/debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/error.h"
#include "mbedtls/certs.h"

#include "mbedtls/ssl_ciphersuites.h"

#include <string.h>

#include "mbedtls/security_level.h"

#define SERVER_PORT "4433"
#define SERVER_NAME "localhost"
#define CLIENT_MSG "ping"

#define DEBUG_LEVEL 1

static void my_debug( void *ctx, int level,
                      const char *file, int line,
                      const char *str )
{
    ((void) level);

    mbedtls_fprintf( (FILE *) ctx, "%s:%04d: %s", file, line, str );
    fflush(  (FILE *) ctx  );
}

unsigned char *generate_random_bytes(int num_bytes) {
    if (num_bytes < 1) {
        mbedtls_printf("[!!!] Requested number of random bytes is %d. Returning null...\n", num_bytes);
        return NULL;
    } else {
        mbedtls_printf("Generating %d random bytes...\n", num_bytes);
    }

    unsigned char* rand_bytes = malloc(num_bytes);

    for (int i = 0; i < num_bytes; i++){
        rand_bytes[i] = rand();
    }

    return rand_bytes;
}

int main( int argc, char** argv )
{


    char *ciphersuite_str_id;
    unsigned char *send_buf;
    int ciphersuite_id, num_bytes_to_send, num_bytes_written = 0;
    int custom_cipher_suite[2];

    int ret, len, num_bytes_read = 0;
    mbedtls_net_context server_fd;
    uint32_t flags;
    unsigned char buf[1024];
    const char *pers = "ssl_client1";
    char *chosen_cipher;

    mbedtls_entropy_context entropy;
    mbedtls_ctr_drbg_context ctr_drbg;
    mbedtls_ssl_context ssl;
    mbedtls_ssl_config conf;
    mbedtls_x509_crt cacert;

    unsigned short int is_use_psk = 0;


    // parse arg
    if (argc < 2) {
        mbedtls_printf("[!!!] No ciphersuite argument provided\n");
        return ( -1 );
    }

    if (argc > 2) {
        // num of bytes to send provided
        num_bytes_to_send = strtol(argv[2], NULL, 10);
    }


    srand((unsigned int) time(NULL));
    // generate random bytes to send (if needed)
    send_buf = generate_random_bytes(num_bytes_to_send);

#ifdef USE_RSA_2048
    mbedtls_printf("Using RSA 2048 security\n");
#endif

    ciphersuite_str_id = argv[1];

    ciphersuite_id = strtol(ciphersuite_str_id, NULL, 10);
    custom_cipher_suite[0] = ciphersuite_id;
    custom_cipher_suite[1] = 0;

    chosen_cipher = mbedtls_ssl_get_ciphersuite_name(ciphersuite_id);
    mbedtls_printf("Chosen ciphersuite id: %d\n\t%s\n", custom_cipher_suite[0], chosen_cipher);

#if defined(MBEDTLS_DEBUG_C)
    mbedtls_debug_set_threshold( DEBUG_LEVEL );
#endif

    /*
     * 0. Initialize the RNG and the session data
     */
    mbedtls_net_init( &server_fd );
    mbedtls_ssl_init( &ssl );
    mbedtls_ssl_config_init( &conf );
    mbedtls_x509_crt_init( &cacert );
    mbedtls_ctr_drbg_init( &ctr_drbg );

    mbedtls_dhm_context dhm;
    mbedtls_dhm_init( &dhm );

    const char* use_psk = "PSK";
    const char* use_rsa = "RSA"; // for RSA_PSK ciphersuites

    if (strstr(chosen_cipher, use_psk) != NULL) {
        mbedtls_printf("[INFO]Using PSK\n");
        is_use_psk = 1;

        // For the case where RSA_PSK ciphersuites are used. Here, we still want to use a certificate.
        // This "if" can be refactored and put above, but I'd like to keep it here for easier readability.
        if (strstr(chosen_cipher, use_rsa) != NULL) {
            is_use_psk = 0;
        }


        ret = mbedtls_ssl_conf_psk( &conf, psk_value, sizeof(psk_value), psk_identity, strlen(psk_identity));
        if( ret != 0 )
        {
            mbedtls_printf( "  failed\n  mbedtls_ssl_conf_psk returned -0x%04X\n\n", - ret );
            goto exit;
        }

    }

    mbedtls_printf( "\n  . Seeding the random number generator..." );
    fflush( stdout );

    mbedtls_entropy_init( &entropy );
    if( ( ret = mbedtls_ctr_drbg_seed( &ctr_drbg, mbedtls_entropy_func, &entropy,
                                       (const unsigned char *) pers,
                                       strlen( pers ) ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ctr_drbg_seed returned %d\n", ret );
        goto exit;
    }

    mbedtls_printf( " ok\n" );

    /*
     * 0. Initialize certificates
     */
    if (is_use_psk == 0) {

        mbedtls_printf("  . Loading the CA root certificate ...");
        fflush(stdout);

        ret = mbedtls_x509_crt_parse(&cacert, (const unsigned char *) mbedtls_test_cas_pem,
                                     mbedtls_test_cas_pem_len);
        if (ret < 0) {
            mbedtls_printf(" failed\n  !  mbedtls_x509_crt_parse returned -0x%x\n\n", -ret);
            goto exit;
        }

        mbedtls_printf(" ok (%d skipped)\n", ret);
    } else {

        mbedtls_printf("\tSkipping certificate loading because a PSK ciphersuite is in use\n");
    }

    /*
     * 1. Start the connection
     */
    mbedtls_printf( "  . Connecting to tcp/%s/%s...", SERVER_NAME, SERVER_PORT );
    fflush( stdout );

    if( ( ret = mbedtls_net_connect( &server_fd, SERVER_NAME,
                                     SERVER_PORT, MBEDTLS_NET_PROTO_TCP ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_net_connect returned %d\n\n", ret );
        goto exit;
    }

    mbedtls_printf( " ok\n" );

    /*
     * 2. Setup stuff
     */
    mbedtls_printf( "  . Setting up the SSL/TLS structure..." );
    fflush( stdout );

    if( ( ret = mbedtls_ssl_config_defaults( &conf,
                                             MBEDTLS_SSL_IS_CLIENT,
                                             MBEDTLS_SSL_TRANSPORT_STREAM,
                                             MBEDTLS_SSL_PRESET_DEFAULT ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ssl_config_defaults returned %d\n\n", ret );
        goto exit;

    }
    mbedtls_printf( " ok\n" );

    // Enable RC4 ciphers
    mbedtls_ssl_conf_arc4_support(&conf, MBEDTLS_SSL_ARC4_ENABLED);

    mbedtls_printf( "  . Setting up custom ciphersuite..." );
    fflush( stdout );

    mbedtls_ssl_conf_ciphersuites(&conf, custom_cipher_suite);
    mbedtls_printf(" ok\n");


    /* OPTIONAL is not optimal for security,
     * but makes interop easier in this simplified example */
    mbedtls_ssl_conf_authmode( &conf, MBEDTLS_SSL_VERIFY_REQUIRED );
    mbedtls_ssl_conf_ca_chain( &conf, &cacert, NULL );
    mbedtls_ssl_conf_rng( &conf, mbedtls_ctr_drbg_random, &ctr_drbg );
    mbedtls_ssl_conf_dbg( &conf, my_debug, stdout );

    if( ( ret = mbedtls_ssl_setup( &ssl, &conf ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ssl_setup returned %d\n\n", ret );
        goto exit;
    }

    if( ( ret = mbedtls_ssl_set_hostname( &ssl, SERVER_NAME ) ) != 0 )
    {
        mbedtls_printf( " failed\n  ! mbedtls_ssl_set_hostname returned %d\n\n", ret );
        goto exit;
    }

    mbedtls_ssl_set_bio( &ssl, &server_fd, mbedtls_net_send, mbedtls_net_recv, NULL );

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
     * 4. Handshake
     */
    mbedtls_printf( "  . Performing the SSL/TLS handshake..." );
    fflush( stdout );

    while( ( ret = mbedtls_ssl_handshake( &ssl ) ) != 0 )
    {
        if( ret != MBEDTLS_ERR_SSL_WANT_READ && ret != MBEDTLS_ERR_SSL_WANT_WRITE )
        {
            mbedtls_printf( " failed\n  ! mbedtls_ssl_handshake returned -0x%x\n\n", -ret );
            goto exit;
        }
    }

    mbedtls_printf( " ok\n" );
    chosen_cipher = mbedtls_ssl_get_ciphersuite( &ssl );
    mbedtls_printf("   Negotiated Ciphersutie: %s\n", chosen_cipher);

    /*
     * 5. Verify the server certificate
     */
    if (is_use_psk == 0) {

        mbedtls_printf("  . Verifying peer X.509 certificate...");

        /* In real life, we probably want to bail out when ret != 0 */
        if ((flags = mbedtls_ssl_get_verify_result(&ssl)) != 0) {
            char vrfy_buf[512];

            mbedtls_printf(" failed\n");

            mbedtls_x509_crt_verify_info(vrfy_buf, sizeof(vrfy_buf), "  ! ", flags);

            mbedtls_printf("%s\n", vrfy_buf);
        } else
            mbedtls_printf(" ok\n");
    } else {

        mbedtls_printf("\tSkipping certificate verification because a PSK ciphersuite is in use\n");
    }

    /*
     * 3. Write the GET request
     */
    mbedtls_printf( "  > Write to server:" );
    fflush( stdout );

    len = num_bytes_to_send;
    mbedtls_printf("len of send_buf = %d\n", len);
    ret = 0;

    while( ret = mbedtls_ssl_write( &ssl, send_buf + ret, len) )
    {

        mbedtls_printf("\n\nret=%d\n\n", ret);

        num_bytes_written += ret;

        if (ret == len) {
            break;
        }

        len += ret ;
    }

    mbedtls_printf( " %d bytes written\n%s\n", num_bytes_written, (char *) send_buf );

    /*
     * 7. Read the HTTP response
     */
    mbedtls_printf( "  < Read from server:" );
    fflush( stdout );

    do
    {
        len = sizeof( buf );
        memset( buf, 0, sizeof( buf ) );
        ret = mbedtls_ssl_read( &ssl, buf, len );

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
    }
    while( 1 );

    mbedtls_printf( " %d bytes read\n\n", num_bytes_read);
    mbedtls_ssl_close_notify( &ssl );

    exit:

#ifdef MBEDTLS_ERROR_C
    if( ret != 0 )
    {
        char error_buf[100];
        mbedtls_strerror( ret, error_buf, 100 );
        mbedtls_printf("Last error was: %d - %s\n\n", ret, error_buf );

        if (ret == MBEDTLS_ERR_SSL_PEER_CLOSE_NOTIFY ) {
            // if the server closed the connection it's all good
            // let's make sure that the app returns 0 here, so that the script
            // does not treat this as an error.
            ret = 0;
        }
    }
#endif

    mbedtls_net_free( &server_fd );

    mbedtls_x509_crt_free( &cacert );
    mbedtls_ssl_free( &ssl );
    mbedtls_ssl_config_free( &conf );
    mbedtls_ctr_drbg_free( &ctr_drbg );
    mbedtls_entropy_free( &entropy );

#if defined(_WIN32)
    mbedtls_printf( "  + Press Enter to exit this program.\n" );
    fflush( stdout ); getchar();
#endif

    return( ret );
}
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ENTROPY_C && MBEDTLS_SSL_TLS_C &&
          MBEDTLS_SSL_CLI_C && MBEDTLS_NET_C && MBEDTLS_RSA_C &&
          MBEDTLS_CERTS_C && MBEDTLS_PEM_PARSE_C && MBEDTLS_CTR_DRBG_C &&
          MBEDTLS_X509_CRT_PARSE_C */

