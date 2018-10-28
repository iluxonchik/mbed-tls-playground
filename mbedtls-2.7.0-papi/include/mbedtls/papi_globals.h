//
// Created by iluxonchik on 27-10-2018.
//

#ifndef MBED_TLS_PAPI_GLOBALS_H
#define MBED_TLS_PAPI_GLOBALS_H

int papi_retval;
/**
 * mbedtls_ssl_handshake
 */

float mbedtls_ssl_handshake_realtime;
float mbedtls_ssl_handshake_proctime;
float mbedtls_ssl_handshake_mflops;
long long mbedtls_ssl_handshake_flpins;

#endif //MBED_TLS_PAPI_GLOBALS_H
