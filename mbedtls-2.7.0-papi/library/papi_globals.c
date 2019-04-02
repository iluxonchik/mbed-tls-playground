#include <mbedtls/platform.h>
#include "mbedtls/papi_globals.h"


extern long long mbedtls_ssl_handshake_proctime;
extern long long mbedtls_ssl_handshake_cycles_virt;

extern long long mbedtls_auth_proctime;
extern long long mbedtls_auth_cycles_virt;

/* Cost of doing and RSA encryption and decryption */
extern long long mbedtls_pk_decrypt_proctime;
extern long long mbedtls_pk_decrypt_cycles_virt;
extern long long mbedtls_pk_encrypt_proctime;
extern long long mbedtls_pk_encrypt_cycles_virt;

// RSA/ECDSA signature creation (private key)
extern long long mbedtls_sign_proctime;
extern long long mbedtls_sign_cycles_virt;

// RSA/ECDSA sigature verification (public key)
extern long long mbedtls_verify_proctime;
extern long long mbedtls_verify_cycles_virt;

// ECDH generate keypair
extern long long mbedtls_ecdh_gen_keypair_proctime;
extern long long mbedtls_ecdh_gen_keypair_cycles_virt;

// ECDH generate shared secret
extern long long mbedtls_ecdh_gen_shared_proctime;
extern long long mbedtls_ecdh_gen_shared_cycles_virt;

// DH generate keypair
extern long long mbedtls_dh_gen_keypair_proctime;
extern long long mbedtls_dh_gen_keypair_cycles_virt;

// DH generate shared secret
extern long long mbedtls_dh_gen_shared_proctime;
extern long long mbedtls_dh_gen_shared_cycles_virt;


void print_stats() {

    mbedtls_printf("handshake_virttime %lld\n", mbedtls_ssl_handshake_proctime);
    mbedtls_printf("handshake_virtcyc %lld\n", mbedtls_ssl_handshake_cycles_virt);

    mbedtls_printf("auth_virttime %lld\n", mbedtls_auth_proctime);
    mbedtls_printf("auth_virtcyc %lld\n", mbedtls_auth_cycles_virt);

    mbedtls_printf("asym_encrypt_virttime %lld\n", mbedtls_pk_encrypt_proctime);
    mbedtls_printf("asym_encrypt_virtcyc %lld\n", mbedtls_pk_encrypt_cycles_virt);

    mbedtls_printf("asym_decrypt_virttime %lld\n", mbedtls_pk_decrypt_proctime);
    mbedtls_printf("asym_decrypt_virtcyc %lld\n", mbedtls_pk_decrypt_cycles_virt);

    mbedtls_printf("sign_virttime %lld\n", mbedtls_sign_proctime);
    mbedtls_printf("sign_virtcyc %lld\n", mbedtls_sign_cycles_virt);

    mbedtls_printf("verify_virttime %lld\n", mbedtls_verify_proctime);
    mbedtls_printf("verify_virtcyc %lld\n", mbedtls_verify_cycles_virt);

    mbedtls_printf("ecdh_gen_keypair_virttime %lld\n", mbedtls_ecdh_gen_keypair_proctime);
    mbedtls_printf("ecdh_gen_keypair_virtcyc %lld\n", mbedtls_ecdh_gen_keypair_cycles_virt);

    mbedtls_printf("ecdh_gen_shared_virttime %lld\n", mbedtls_ecdh_gen_shared_proctime);
    mbedtls_printf("ecdh_gen_shared_virtcyc %lld\n", mbedtls_ecdh_gen_shared_cycles_virt);

    mbedtls_printf("dh_gen_keypair_virttime %lld\n", mbedtls_dh_gen_keypair_proctime);
    mbedtls_printf("dh_gen_keypair_virtcyc %lld\n", mbedtls_dh_gen_keypair_cycles_virt);

    mbedtls_printf("dh_gen_shared_virttime %lld\n", mbedtls_dh_gen_shared_proctime);
    mbedtls_printf("dh_gen_shared_virtcyc %lld\n", mbedtls_dh_gen_shared_cycles_virt);

}
