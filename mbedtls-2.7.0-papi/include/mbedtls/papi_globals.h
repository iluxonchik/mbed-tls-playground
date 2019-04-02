
#ifndef MBED_TLS_PAPI_GLOBALS_H
#define MBED_TLS_PAPI_GLOBALS_H

int papi_retval;

void print_stats();

/**
 * mbedtls_ssl_handshake
 */

// Handshake costs
long long mbedtls_ssl_handshake_proctime;
long long mbedtls_ssl_handshake_cycles_virt;

// Total authentication(sign/verify + eventual RSA encrypt/decrypt)
long long mbedtls_auth_proctime;
long long mbedtls_auth_cycles_virt;

// RSA/ECDSA signature creation (private key)
long long mbedtls_sign_proctime;
long long mbedtls_sign_cycles_virt;

// RSA/ECDSA sigature verification (public key)
long long mbedtls_verify_proctime;
long long mbedtls_verify_cycles_virt;

// RSA encryption
long long mbedtls_pk_encrypt_proctime;
long long mbedtls_pk_encrypt_cycles_virt;

// RSA decryption
long long mbedtls_pk_decrypt_proctime;
long long mbedtls_pk_decrypt_cycles_virt;


// ECDH generate keypair
long long mbedtls_ecdh_gen_keypair_proctime;
long long mbedtls_ecdh_gen_keypair_cycles_virt;

// ECDH generate shared secret
long long mbedtls_ecdh_gen_shared_proctime;
long long mbedtls_ecdh_gen_shared_cycles_virt;

// DH generate keypair
long long mbedtls_dh_gen_keypair_proctime;
long long mbedtls_dh_gen_keypair_cycles_virt;

// DH generate shared secret
long long mbedtls_dh_gen_shared_proctime;
long long mbedtls_dh_gen_shared_cycles_virt;


#endif //MBED_TLS_PAPI_GLOBALS_H
