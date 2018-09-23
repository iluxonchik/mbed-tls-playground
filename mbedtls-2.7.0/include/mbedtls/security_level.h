/*
 * Security level configuration.
 */

#ifndef MBED_TLS_SECURITY_LEVEL_H
#define MBED_TLS_SECURITY_LEVEL_H

/* [!!!] IMPORTANT: configuration NOTE !!!
 *
 * 1. Go to certs.h file and configure the desired security level by uncommening the appropriate #define USE_RSA_XXXX.
 * Only one of the USE_RSA_XXXX can be defined! The security level of the remaining algorithms (e.g. ECC) will be
 * adjusted accordingly.
 *
 * 2. Change the order of the preferred curves in `ecp.c` [for `ECDHE-*` ciphersuites]. For example,
 * if you want 512 bit EC keys to be used in `ECHDE-*` ciphersuites, you should put

    #if defined(MBEDTLS_ECP_DP_SECP521R1_ENABLED)
        { MBEDTLS_ECP_DP_SECP521R1,    25,     521,    "secp521r1"         },
    #endif

    before

    #if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
        { MBEDTLS_ECP_DP_SECP256R1,    23,     256,    "secp256r1"         },
    #endif

    or vice-versa if you want 256 bit EC keys.

  Here, the first one found in the list will be used.



 */

//#define USE_RSA_1024
//#define USE_RSA_2048
//#define USE_RSA_4092
#define USE_RSA_8192

// #define USE_RSA_3072
//#define USE_RSA_7680
//#define USE_RSA_15360

/* You probably don't want this activated. I put it here so that I would not have to comment unused code (for now) out. */
// #define USE_OTHER_CURVES

/*
* Here, you have a lot of options for the PSK key sizes. Set the PSK_VALUE to the one
* that you want to use.
*
* To generate PSKs you can use openssl. For example, to generate a 256 bit (32 byte) PSK, you can simply run:
*     $ openssl rand -hex 32
*
*/

#define PSK_112_BIT_RSA_1024 "883984c0a50fdf4e3e26"
#define PSK_112_BIT_RSA_2048 "b6ee6292fc934dc226c85698b6b4"
#define PSK_112_BIT_RSA_4092 "417bcecdce3a7b11274169c6d3cc440161fe7d8a"
#define PSK_112_BIT_RSA_8192 "9a7b270d460c0f350f1477ff53be10db0f3332d6b8edeb42b8aa8a"
#define PSK_127_BIT_RSA_3072 "2b88bcc7caec33b6cf61cdf06887d683"
#define PSK_192_BIT_RSA_7680 "ed78bd38062e4e033136da8cc6022d7129bdd09ce06b5d63"
#define PSK_256_BIT_RSA_15360 "71bc53a3beeaa416a4050653cec13d288e3eb692959cd0828499b702739e482c"

/* --- BEGIN RSA_1024 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_1024                              \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICZjCCAU4CCQDlZKiuYh+0CTANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwOTIzMTA1OTEzWhcNMjEwNjE5MTA1OTEzWjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MIGfMA0GCSqGSIb3\r\n" \
"DQEBAQUAA4GNADCBiQKBgQDWviOQGhtbYYnT2CsAwOV5zwaAlHGtaf0160RvlkEq\r\n" \
"ZiVe6kUCXCPDtanAoq8rc5E9sD5CYWWd9UDtM3KgNJ/FW9cwWfsM+OBi7S8YLa0Z\r\n" \
"iDNCM695fuXrd0X9Nv8snEltA+4ge6ljmyDDqDzqqYW9JP0bqXhU30Riydn4HNQ1\r\n" \
"QwIDAQABMA0GCSqGSIb3DQEBCwUAA4IBAQARGvxpQVSpCFKJR5ltFHHbRe7RMXkI\r\n" \
"PZGkvcs6fTpZ982HEez15nqhfWp2JFfLh0xn1+iu8DcHxgGojWJDuAF3sAypsbFp\r\n" \
"dp960PP8v1poTK8K1qZYThxKLc6arx0MFdYAK9xD4sPGSAI5nZrjsHyJmVqHDidc\r\n" \
"N5ems991F9T0xAK5W+hw+wRPCRBpv0C7GEygt2e94bgvhpLC4bNzmZNQjNWcBYFf\r\n" \
"cp/i1q9vPzA0temXukIz4jfk+sJFHI7iThvBPqJ5qOGJ2ehzc6J943iUMiPbYAvk\r\n" \
"dWwAytTpl1wrlLyTjdaAWXL/Q+P+cZkhT69HTICVfYYsOmtbZ8+Mwkgd\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_1024                        \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIBXjCCAQQCCQDlZKiuYh+0CzAKBggqhkjOPQQDAjBOMQswCQYDVQQGEwJOTDET\r\n" \
"MBEGA1UECAwKU29tZS1TdGF0ZTERMA8GA1UECgwIUG9sYXJTU0wxFzAVBgNVBAMM\r\n" \
"DlBvbGFyU1NMIEVDIENBMB4XDTE4MDkyMzEwNTkxM1oXDTIxMDYxOTEwNTkxM1ow\r\n" \
"MzELMAkGA1UEBhMCTkwxEDAOBgNVBAoMB21iZWRUTFMxEjAQBgNVBAMMCWxvY2Fs\r\n" \
"aG9zdDBGMBAGByqGSM49AgEGBSuBBAAfAzIABP4UT3OwBgKamW9/4QJRBRULs5w8\r\n" \
"pFI2XXzZP7uI2hH7uwbLK+kHCc2L/AJqCOFfdjAKBggqhkjOPQQDAgNIADBFAiAl\r\n" \
"56l2LFOEPTq2O+snCRI3WK63cPIMT9fkkrpXX0+xyQIhAJXy3KgTPXMPTzjypX2t\r\n" \
"5MG1Loz6zTyzOA3TSp0Vvvql\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_1024                         \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICCzCB9AIJAOVkqK5iH7QKMA0GCSqGSIb3DQEBCwUAMDsxCzAJBgNVBAYTAk5M\r\n" \
"MREwDwYDVQQKDAhQb2xhclNTTDEZMBcGA1UEAwwQUG9sYXJTU0wgVGVzdCBDQTAe\r\n" \
"Fw0xODA5MjMxMDU5MTNaFw0yMTA2MTkxMDU5MTNaMDMxCzAJBgNVBAYTAk5MMRAw\r\n" \
"DgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwRjAQBgcqhkjOPQIB\r\n" \
"BgUrgQQAHwMyAAT+FE9zsAYCmplvf+ECUQUVC7OcPKRSNl182T+7iNoR+7sGyyvp\r\n" \
"BwnNi/wCagjhX3YwDQYJKoZIhvcNAQELBQADggEBAD0hgqXdss5esCNOCnczsIxw\r\n" \
"tQZx1n3uW8RkGOPPuZ0OyhiFc6zn2KibAzZ1/pPrrrrmh0luRPw5dgjLuXFKD9KM\r\n" \
"Tev9ZtHfixFMATPKdDTdEeFykWCq6uX1vCrvIhPyKemdAmlot1CN0dBuxohrKfnA\r\n" \
"5Z6ydoLhG9k/pUYv2LL7HxketAR2DPekiCl62oJMUgERDfZ56DtYtoaospEVHOTX\r\n" \
"SCfuw6LmZOSWw4YEor8aO4eaiJBBMFXtwrBEvuRkEthj1ZbtzPQ3ycJRWWQIuQ5I\r\n" \
"VBUW1ar5zwowTzJ5frWAyoq/z+7SpjUkMHRkg7X0DhluWjF4uo49NMVhp5qD64Q=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_1024                               \
"-----BEGIN EC PRIVATE KEY-----\r\n" \
"MFwCAQEEGOuLXSxH4OwhhvEpjLnIQW7NslWOO3H/vKAHBgUrgQQAH6E0AzIABP4U\r\n" \
"T3OwBgKamW9/4QJRBRULs5w8pFI2XXzZP7uI2hH7uwbLK+kHCc2L/AJqCOFfdg==\r\n" \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_1024                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"MIICXAIBAAKBgQDWviOQGhtbYYnT2CsAwOV5zwaAlHGtaf0160RvlkEqZiVe6kUC\r\n" \
"XCPDtanAoq8rc5E9sD5CYWWd9UDtM3KgNJ/FW9cwWfsM+OBi7S8YLa0ZiDNCM695\r\n" \
"fuXrd0X9Nv8snEltA+4ge6ljmyDDqDzqqYW9JP0bqXhU30Riydn4HNQ1QwIDAQAB\r\n" \
"AoGANJmscl7CtraEoTyBBBU74INib1ptIfIlUPDI+aBPZAhTPRWbQ8G4DPdRllsD\r\n" \
"F1yehgLGrVHYJ0Hs3m1MtYtOWwF8tIc3TE6d630VzSBd0OKwNvhPOw+pSGj5BaSN\r\n" \
"afiuSbn6nTKWfCkd6zWg+KfOYKQ6FpwdGjd8R+t5SlyktZECQQDzDwUIOVXh6M+y\r\n" \
"MN/3CnhdLs/s/120DZB9DSgAm1dh+AMq5/HiI0pDPunYUuKH2Y4jO5LKQlaARKD0\r\n" \
"ydmt+IUJAkEA4i0plRakOb6Hx8EPDRPuIxL2uZmd/KBxhcz8/dMOXXINA9Y99B/y\r\n" \
"Bh6rC9tS7WWwob4Led8HRrQc/YBr58zm6wJAalB1iQVbNXdZ8b1DGZGw2EFznVyN\r\n" \
"pgYQ30Hz72ADNsz+xbOyr5F0GDnam06V24oji/Gw4Vtm7rAWHzxzRI9h0QJBAIf3\r\n" \
"qnXMBLIKDkpRjyDHiHNhZR0ycj16noRXNQfKJ2qZs6VI2Dm4MqDnMuCP2wyIA2VY\r\n" \
"gEGliBRDFuJ2n2fcUD0CQB+IkoXau73nZxR0YzmnKJd7ihiRGIfiYdDJsfHMi2Xt\r\n" \
"D/BZ3aRHEGB3tIL74Dw3t1Djmj7rurP7lLYgJl5mf9s=\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_1024                                 \
"-----BEGIN DH PARAMETERS-----\r\n" \
"MIIBHgKBgQDZXKxv0U8uuriI9HmQfbmKPkn1hAT0J+oYWKK0pw74tTPjcXhgPruE\r\n" \
"SYH2oKlXDmAIE8QDmONjf78cIIpA8z736+WdtLJfZ8bemhD+r4EZsUuAe5qZG0wv\r\n" \
"yPKIgUecA2p5F3BbSu9rT/BoLR2jY4d0I+XOTQFc3vvPBewaRjbMcQKBgC8G5FXw\r\n" \
"uN55rh9Dkf+LFClN6+FfN31QVwK/5C3vtah2GECNpDWaTbsOCsUG3bwhhGhxbPsP\r\n" \
"9HYzv1UIp6JIEQE/1e5qcjF526JM8kEHxCfNK6K7dTnYjQIWL5z/senXGVQyHsqA\r\n" \
"yiOkhCwIgDxjOwmY4H274hwvgiTeAG49XQbXAhUA/rLUUk4+9FNZrYUeKZpOd10l\r\n" \
"WJ8=\r\n" \
"-----END DH PARAMETERS-----\r\n"

/* ---- END RSA_1024 ---- */


/* --- BEGIN RSA_2048 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_2048                              \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIC6jCCAdICCQDMiMNvJz3ujzANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwOTIzMTEwNjA2WhcNMjEwNjE5MTEwNjA2WjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG\r\n" \
"9w0BAQEFAAOCAQ8AMIIBCgKCAQEAxSsEsyUAj/EnYQfGUVziurIwIZFA733taBUE\r\n" \
"LhKU8jqY+679UB0qla3sCUdcWFd/8EeB83zIK+3E9U9Bnj2kjipX20tZ56e0RPqP\r\n" \
"F9LeX5aHo3jpjet337gA+RtKy0jU/tXRKWfKUgnUyxhR1Ae/zIEjftrvgmUNVJYX\r\n" \
"N+w0VQeoWXRa+XoIl2rK1v6kPYV69rJio41fwPK6xuN70I3AjJOD77cNVZ7XrX6l\r\n" \
"B6pKbQ9ls21+cV9m7zSGvEsgCkYOrBGR7EDWP6NV2mGVopJNunBiRWqGeaMXQuaN\r\n" \
"tCoZmt0P6Df3uK4Q5cbWhLmM2/gKe79vtiLcTgM5pl+QQdqrYQIDAQABMA0GCSqG\r\n" \
"SIb3DQEBCwUAA4IBAQCeObbsaOTz/pwJvyzm/S/HB8C81uzfJ9YnguhdAJmUrLVS\r\n" \
"GY5nUzgYsMJ9YwANQyTwlY+IBCwTy+QhJxiQELCyXsYDkXPhoaqmoTtp+uV2RMIX\r\n" \
"tJUBAMyrhyONwO22bCE5qa8h7WrW/vtX09ZeD9bsUNQDWQO3SrNhf9upYIu8Ke0J\r\n" \
"lkt0MrzMF98wz+QqFvfEUNIdnH0h6TWiz9EA9n2nB/e/pbXe7Ev7Ebpi/SZ/1Kwe\r\n" \
"ExP5oiHnvD9rSJdX95FiHxfmxV0gYQkDz+ZXSu4bjnFdMb5BS19l4KsCO32R4fCv\r\n" \
"nXiNmRXEgsmjEq5ny59aBgJeyO6W2Ge7VDUvQb2T\r\n" \
"-----END CERTIFICATE-----\r\n"


#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_2048                        \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIBcjCCARcCCQDMiMNvJz3ukTAKBggqhkjOPQQDAjBOMQswCQYDVQQGEwJOTDET\r\n" \
"MBEGA1UECAwKU29tZS1TdGF0ZTERMA8GA1UECgwIUG9sYXJTU0wxFzAVBgNVBAMM\r\n" \
"DlBvbGFyU1NMIEVDIENBMB4XDTE4MDkyMzExMDYwNloXDTIxMDYxOTExMDYwNlow\r\n" \
"MzELMAkGA1UEBhMCTkwxEDAOBgNVBAoMB21iZWRUTFMxEjAQBgNVBAMMCWxvY2Fs\r\n" \
"aG9zdDBZMBMGByqGSM49AgEGCCqGSM49AwEHA0IABNS2AH83DodehouqK2aT09qN\r\n" \
"+ychUJuEd6SZLWGegbwrFcFuiqajlYuMUj9IpT5zWviuR2fxQa3NQKh5tdLF4GEw\r\n" \
"CgYIKoZIzj0EAwIDSQAwRgIhALRgzj2GdczjVLxI0wWUfeM9UbONiPdIpk8yh18i\r\n" \
"wJ7cAiEA0sUkCl6OJfM8yUa+KNaVJxHEgqQFSeqDr+k7dDufQgM=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_2048                         \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICHzCCAQcCCQDMiMNvJz3ukDANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwOTIzMTEwNjA2WhcNMjEwNjE5MTEwNjA2WjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MFkwEwYHKoZIzj0C\r\n" \
"AQYIKoZIzj0DAQcDQgAE1LYAfzcOh16Gi6orZpPT2o37JyFQm4R3pJktYZ6BvCsV\r\n" \
"wW6KpqOVi4xSP0ilPnNa+K5HZ/FBrc1AqHm10sXgYTANBgkqhkiG9w0BAQsFAAOC\r\n" \
"AQEAFs7BIZs1LsLCVFC+p9wgi4EYNbh6USEZ+LA494tyo1UzvrXHM8R/YA1jQRtd\r\n" \
"PdvdGl/yRP2Lnmj0CCW0WWwuhea8zJcJzA2k5yZBF5d+QUu+jX788Ju2av2EYBZU\r\n" \
"+AjsBKA1FP9GT6wJlEmCyJjDpD8Em10QQFTOUqzhgsk3Phow0fJCfvMa9AHmH3BT\r\n" \
"5bQ0boqwImB9vUZusxJl5RXMvnxEEQtrRfI2zcVhspkzU8dqtaX2sPE6NUG3vGKR\r\n" \
"URMbwksrffjRuWk5VvwML64fB+HE6dNMnlEE/nNmyOxl1CsPJvRjGYy3VA0l0fUT\r\n" \
"WLeL7wLukVDPAzlyhgCwELvOpg==\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_2048                               \
"-----BEGIN EC PRIVATE KEY-----\r\n" \
"MHcCAQEEIAVbJXk8yBbdmdLhczDxj5HojPjZQXJEWMBZU5EVlWDdoAoGCCqGSM49\r\n" \
"AwEHoUQDQgAE1LYAfzcOh16Gi6orZpPT2o37JyFQm4R3pJktYZ6BvCsVwW6KpqOV\r\n" \
"i4xSP0ilPnNa+K5HZ/FBrc1AqHm10sXgYQ==\r\n" \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_2048                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"MIIEowIBAAKCAQEAxSsEsyUAj/EnYQfGUVziurIwIZFA733taBUELhKU8jqY+679\r\n" \
"UB0qla3sCUdcWFd/8EeB83zIK+3E9U9Bnj2kjipX20tZ56e0RPqPF9LeX5aHo3jp\r\n" \
"jet337gA+RtKy0jU/tXRKWfKUgnUyxhR1Ae/zIEjftrvgmUNVJYXN+w0VQeoWXRa\r\n" \
"+XoIl2rK1v6kPYV69rJio41fwPK6xuN70I3AjJOD77cNVZ7XrX6lB6pKbQ9ls21+\r\n" \
"cV9m7zSGvEsgCkYOrBGR7EDWP6NV2mGVopJNunBiRWqGeaMXQuaNtCoZmt0P6Df3\r\n" \
"uK4Q5cbWhLmM2/gKe79vtiLcTgM5pl+QQdqrYQIDAQABAoIBAQCdFfb6m4JlLCbJ\r\n" \
"oZ4ZeL2TLSA3vjhUFqotAIGCC3/rtU/pRbPAPlyNQDIL+nTSVXQzBWW9ji8VAKyp\r\n" \
"HOoUntwaABZbOx939x8izdVvj6tn0NBkJ5M8ZNvuu/TagyoF6BL6rXOlX3HMBtUo\r\n" \
"skmPelUPI9wZ12h3JPeH6sS441GWY8m6hV/40v2bPVSSEQrmWjFOHZzV1sYEC+nJ\r\n" \
"RDCZpkW/94zuVoAGROg/6D8F3NFqT1wcyTfv0sYPMB9A+S3G7oNiRpX6DnToopEq\r\n" \
"0Gd6lmVo8Dk4lncC3Dv2IT8XPhG3Wwgv2pUB80cx7gfrfKzjNNtEPzlgtDnEEhqa\r\n" \
"JyZAZjM5AoGBAPfz1dzSExWQlHjExgiM9C9CL8bguQfvXhdhZP1Yaz5lE6izxoxj\r\n" \
"3j7F2KcYxP46KPUKLUuTXnUr3+/uEbsw4pMPhHLi8w4/y7nvsRcm3g1NYyiIESZQ\r\n" \
"H5XrUfCTNiJNUTU0KS1mYqISDi7FdNY5VckUmpUR6Z/czWgXGe9l/KQ7AoGBAMuR\r\n" \
"OtqIiyFvuai/YjWdQ687gw4KX97XK5btcRwZKU6JD45T6t0Ta77C1cLfUKezdc8A\r\n" \
"hA+jwPZNo+z2uFOKmPtUBJWERDTACdhaWaSGXRaCa5iEveWXzZ+NT3UR06a2PTlO\r\n" \
"K/fY4Lr7le8EnzWU7TLqEY7fWD1fULZs/fw2PsETAoGAO4sInoCsKI+Rt/a4/7Cp\r\n" \
"qvef9YhdprQqyj6PO++RwWgQcoDJe0k4Q6bLQkVGeS6KS13oRq/bDRQ+MKXhCCzT\r\n" \
"HDGrwtMRPyi+yaXvxvmEdXlSCJe0VpkDHMNn5/fSFiavC7G8+bQOl5DyavTr+83E\r\n" \
"9gbGoGmuyr8BbK+vgLfjFaUCgYB3tr/CtpwDnN21RF+wIf0k9z2aKzW4KhfjWV20\r\n" \
"ZYOqQOZaEDXFr18kvxXQ1V1sUhiNFMOVIvsenggyGeHKl25iF0Xe2/r0fp8Lkg63\r\n" \
"t6DU1PwLpLy8Yaq2EvdQZJxwpSmaIsOurOd0bvH8r14lt6BK2eZbfDM7XGtt7Ojs\r\n" \
"wsXi6wKBgAPY9nsu/ml3LxW4nX9ZLDImYv9AEJXmm/SWiu8IUAcWJLg4SvIRYZkj\r\n" \
"qVsPgjZ6B1AXlTZedXjuzEUl/YI+0CGnP1OV9q4otOHO8GFSkW42k3h8LvdDnOqt\r\n" \
"2RJJhfVkrpmxQG7r6MGIcVb3Xtn2+D+8y39QJHC33XJbwbgECoyI\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_2048                                 \
"-----BEGIN DH PARAMETERS-----\r\n"                                    \
"MIICLQKCAQEA0JqRzdj1Fi8N6Kbnnlr6p7EIMQcjakOUEPWs8gBVOQzrzVsZdtTJ\r\n" \
"9Z0wQsbe5sUdpVSr68ToIXZIJa5KEk+5PC5UJJVmUjaPPKaL/N31kbQvlJa1bWYc\r\n" \
"nfchHWwTSssd08XzEdGH+dCrOgGM8/oGLW8cW776kLTOn4V34Ky/q0CcVpkTFwIS\r\n" \
"HFw//wDtarftk13Z2dDBDQ1fzTbbuDulcMx9NFDbieYouGpLdScBzv8rjCh5BfHV\r\n" \
"S2Vh3hKBzquXNbaSgbZ+/xTThEdc14PP+CN+/8dFx4OqsJYJcptHdY9Z6dehZuk7\r\n" \
"8n7oEVRW3DLjcgjkWr5i7tl7HgE7ATQoSQKCAQEAjN3yv5Zu2mKcvjNBZOhCCh9h\r\n" \
"asGiIfXXJpOxg51kJSMpMyI4H9LjkWqFRXp01aN0gUoLIjj/YtNeybLMv1VTrrMc\r\n" \
"SQ9Yd9uRxOi71+51bVYq3a7csw45sNU/+GX1y6hLTFK+GfUQIYOKj6GKOE7sMTi8\r\n" \
"Z5k+a0zIWVtc0t1t5MnKFj2t1zGnIJCydGU3Z8bk5tIRxmOtWvEr8FcbnBoX242j\r\n" \
"q09adWiAQ/dSv3hmYAaor+PONQbUNwoaaij6XjECO7EAbdEPjOBa9pJ8RHivJJSq\r\n" \
"919odfQoV8Cj1TEg7J1mk/UMo0ZunNZmPk2WXlHFPvcgxulUuJ854E9Pr4PfNwIh\r\n" \
"AJ/HyKJAEHX48pQlUIgHupZqPz/yJVEoCMfAAA7OVesd\r\n" \
"-----END DH PARAMETERS-----\r\n"

/* ---- END RSA_2048 ---- */


/* --- BEGIN RSA_4092 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_4092                              \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIID6TCCAtECCQDQjrdMzxZy3TANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwOTIzMTEwNjMyWhcNMjEwNjE5MTEwNjMyWjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MIICITANBgkqhkiG\r\n" \
"9w0BAQEFAAOCAg4AMIICCQKCAgANrEQeteDn500EzdxLJDVBUi4vjR1jSyv2ZOGu\r\n" \
"UoL4RU9DRgCu0nDRx7gpXmJOzsLFGs3nGQZPlbmMD3PVxvxr0us0gRry5VW3zluC\r\n" \
"i2JccSduf7woyjNrmDH5Zd8mOP9JKyzgDKahETOkWkmFlcs9jKNh8AOCNpIHOOr2\r\n" \
"GdMEljvN/JBFW+UcOYR6E2L0s503SHltEIsaYIrq0lTvurUZtHmL678SaRdzg3qV\r\n" \
"8MGSBH7AWQ0ZUW8e8kZhp6ajF44s/3yGhL4YTDkxIr2tFMXKqeUBxgd1St/sMNMf\r\n" \
"g2P+P/X9KH6KjaY1pg6d2eEg9UlyQ5ka/JtbTMruru3YosyXWeOcnfhD2xvwj9Ag\r\n" \
"gSEotINJ60oZhren/3gMxZmtmwCwU/TXtrsn8JRe7Idv2Uk/2MKxJFcO9FDip48m\r\n" \
"GLWuLqHQoHdG4uJoFMnra2NNhcpbFWoTRmV8sryFCI47qIkCkZ1qy5Zgll0Bc8DI\r\n" \
"YgGlxH4urj6chvKpfyLvFf00qYwoqraeOyAxmxakd9h8dAcJ3lM1uzm7SJrLReYV\r\n" \
"QyhaRTxYbwRr9MEKjLV4rt83BPcXdHHR25G4KFzF8ncOQBWixybE49qkjHVQml+F\r\n" \
"AifQqP9qBxTwjQywR29nWi+YCkWeBxf3/Y+EdTXF1Gly15BiP5s4pAiBc5SqeX9P\r\n" \
"rIg/iwIDAQABMA0GCSqGSIb3DQEBCwUAA4IBAQCQMqxMIzOg2y8C8eBxfoEL1Nl5\r\n" \
"+uDA17hMCu1UAHRUmux2Ez0Jvbx/BHFSq8g7Lnva9Xtxo/ZpWx0TvyvVbDTC2OCG\r\n" \
"9L8F6/R8aBn0KtOdkRB1JNGZrXFiZaWJSliEcqQyCEoMU/ntKz7nZguCuEhnd3OG\r\n" \
"zn11IsZuGqIvgb5juEX3871gch5oJUkRXM5quLtIVCQPkrHhF492PxrIF8I72r0V\r\n" \
"0VvdY9JCFyQK+n4noE974LcjVCGu3eVCdn4D1SU/MrcpGsCjb0Z79So88KYh/rpB\r\n" \
"PM/j2L+8EVaPOdoyJO7Uyge9nfkoSQ3vIPcdavOmrNA8ubc6wvoEsoEVHZ5x\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_4092                        \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIBjjCCATQCCQDQjrdMzxZy3zAKBggqhkjOPQQDAjBOMQswCQYDVQQGEwJOTDET\r\n" \
"MBEGA1UECAwKU29tZS1TdGF0ZTERMA8GA1UECgwIUG9sYXJTU0wxFzAVBgNVBAMM\r\n" \
"DlBvbGFyU1NMIEVDIENBMB4XDTE4MDkyMzExMDYzMloXDTIxMDYxOTExMDYzMlow\r\n" \
"MzELMAkGA1UEBhMCTkwxEDAOBgNVBAoMB21iZWRUTFMxEjAQBgNVBAMMCWxvY2Fs\r\n" \
"aG9zdDB2MBAGByqGSM49AgEGBSuBBAAiA2IABKEaOXLosdKZnqkVrtHdiEptjUBB\r\n" \
"i9yM5ZWtWzf/AV41X2o1YwU2bTXOHWquiZRp2mFhb01HsVYV6PJXJZuEsc2YeDHo\r\n" \
"GPacV5MRiV+hU3HhmMe+QgTyxYqPi+WUYhdWgDAKBggqhkjOPQQDAgNIADBFAiAX\r\n" \
"cmEG3XrhEtoeg9abvisx0nU812oifqb+4Wsb+BqVaAIhAO67i+p0ocjKh93UEklH\r\n" \
"sUN2T3HbwLTv5PdIgvr/tgVr\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_4092                         \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICPDCCASQCCQDQjrdMzxZy3jANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwOTIzMTEwNjMyWhcNMjEwNjE5MTEwNjMyWjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MHYwEAYHKoZIzj0C\r\n" \
"AQYFK4EEACIDYgAEoRo5cuix0pmeqRWu0d2ISm2NQEGL3Izlla1bN/8BXjVfajVj\r\n" \
"BTZtNc4daq6JlGnaYWFvTUexVhXo8lclm4SxzZh4MegY9pxXkxGJX6FTceGYx75C\r\n" \
"BPLFio+L5ZRiF1aAMA0GCSqGSIb3DQEBCwUAA4IBAQBpG91eL8mueR2VzpAUyf6c\r\n" \
"rF1fnvaof/0ExlD3oyCSGx8r3KVr+lAiNxpcFvOy1mAx1HQ9tvxMAA4yVHwy+Tfp\r\n" \
"qgvlZKlkuvPHIZX6iWGmCtl9wsCO7Y/7oSd6l1lNs1qay35YA3SSNS/WMLHmIdaN\r\n" \
"Z5CdnM088P8GhS+iRPVckIfoDH9tVVVEVvxUspm0KGDG7p7MYFf9Q5rKqhwr989K\r\n" \
"cXqHBeE/w7OHgJdOa8vHEz28LjIoziX602YmHtKKVtPrgjpgG1zot9xVRBXhzonc\r\n" \
"RxvQwfPP00a5rOfA82qW0V3mkF1LSy7iAE3gdCyF2G3dkRVih8PRa1ubo0l/eCE4\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_4092                               \
"-----BEGIN EC PRIVATE KEY-----\r\n" \
"MIGkAgEBBDBIswlcGwtuLe5nyomwmpSy1KkaycYqZq4ZUCq/ajW2+VsxTSZ5YpME\r\n" \
"5jCFyzJtpDCgBwYFK4EEACKhZANiAAShGjly6LHSmZ6pFa7R3YhKbY1AQYvcjOWV\r\n" \
"rVs3/wFeNV9qNWMFNm01zh1qromUadphYW9NR7FWFejyVyWbhLHNmHgx6Bj2nFeT\r\n" \
"EYlfoVNx4ZjHvkIE8sWKj4vllGIXVoA=\r\n" \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_4092                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"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\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_4092                                 \
"-----BEGIN DH PARAMETERS-----\r\n" \
"MIIELAKCAgEA07sJ6xkM856bPlHDZxbHnjZ1eF9gHUTqT4n8Nbu/F1/+WV4qfUsy\r\n" \
"vELnAiu0f9iA8JWIE3MRHrQKezuchlA+vIMzLhqII21sD+k9SQFnVWi0sPN2YSlv\r\n" \
"KK45EN8rg+mxCDvAEr7vlcshXs/yKgdI/y4UKDGpsuak3qLFnikXvDPvScpq+06i\r\n" \
"uyZO1+zf0BjGKOoAf1seyEBomqrEXf6ahyQa8FlNwVU6UBCQjXzuHx6gM7JLu2gL\r\n" \
"RmXRRnMbs8s6CwT65JEGhkIN5DAyaULZ7/p75PGJ9Cv4BtrkfWesbM8hV0acxVF6\r\n" \
"KpsmzjJ2X16OgTn2mUt9K1Y+Iy7vXqhAB79wrGS2j2F4TujRcaPH2TBRH4TfTWn3\r\n" \
"FAZvXhskM4515Z/DOhKXHk8DvZKacZGPhsYuIF6Lyt1SBs/drs4GCU7cgoG/lRmH\r\n" \
"ImNuT3RUchLadOKb5b+o9sSFXWxjaNufAing8wqVi8YBplDgvFoy4cDk29tkKlKi\r\n" \
"HO75Ga0Niwu9AnNqwm9BLzO5eYTL5pXLCsv5UOwwhzLdOemEp453+tBm8hocmMdX\r\n" \
"pF907BjeosJowwz+NUNxaW+8eMwP8gew7yacboAsAiCoPlVJ+4NycmRZMWm02cMQ\r\n" \
"2XZX/8411o7W8QWzvMykrWFSbBdss2ktrFx6cNYCAdCdqRBOeqWCiaECggIAcum+\r\n" \
"PRZ3qP8tIQxoaOT0JKqBj0kU1R8Um+Qei29i1Ni+cJpChMRE50UxIzu70xlAKXBr\r\n" \
"BhGgW10Ne0+p8WsrvzCYnoe49oXPYg23C4qbbpKRmBd3gDAvhphAdOX0qoblVYL6\r\n" \
"xEAptkXK5ayJxw0IEV/v8jspkLcV1ThztHYfKUF5sjOUiQhGSn9OwMftkU0UfN7O\r\n" \
"tJiKBe014K+ydUwjfpMgWAy2IPozzbIo6zVLg4/33CAs63bbtfQy4BxzLaQl93DB\r\n" \
"DF4WrnUeftEjIiyd85a8oi96UcZzfiE8a9RQADdoaeuDBbofbRgL+O68i6wcDLMr\r\n" \
"k4psShmAwE0rqVoIUBOQybnENR/ukkfa98i1CA5+RP3lNtO3R9V+oNHLxTn6Ff23\r\n" \
"SnH3DKKTyqflgHO57cEhddheSkQjVI4in/h3Ib3/qBXRy3p9H07VJoBdGttDr0l5\r\n" \
"rRHM2enUwLqIYhTfJhAQTzl5T3L2AO4WJxMnPCbA/Q4SDorRDgdZaMt4I3I8k/bh\r\n" \
"uoxROtuAmdjoLpRERlTah9OJMQb2afJdP/D/7gSSIH4ReCj6+t8q5d6gdpPJENh4\r\n" \
"45dcOrsN/TJEpwiMgMsCyJoGbOJUQydvr5RBZvqgJzrGhR4rTbV2gXWI3A/WztZ7\r\n" \
"Ya6KBp+w9nLpW2CRJgSakFaPG8khiUtuUKsZo8oCIQCRAcHIOi123KUXZWXN1wbf\r\n" \
"2AgTwcA4quCOVQbgQlImFQ==\r\n" \
"-----END DH PARAMETERS-----\r\n"

/* ---- END RSA_4092 ---- */


/* --- BEGIN RSA_8192 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_8192                              \
"-----BEGIN CERTIFICATE-----\r\n" \
"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\r\n" \
"-----END CERTIFICATE-----\r\n"


#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_8192                        \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIBtDCCAVoCCQCm75s3Q5Y9tjAKBggqhkjOPQQDAjBOMQswCQYDVQQGEwJOTDET\r\n" \
"MBEGA1UECAwKU29tZS1TdGF0ZTERMA8GA1UECgwIUG9sYXJTU0wxFzAVBgNVBAMM\r\n" \
"DlBvbGFyU1NMIEVDIENBMB4XDTE4MDkyMzExMDcyNVoXDTIxMDYxOTExMDcyNVow\r\n" \
"MzELMAkGA1UEBhMCTkwxEDAOBgNVBAoMB21iZWRUTFMxEjAQBgNVBAMMCWxvY2Fs\r\n" \
"aG9zdDCBmzAQBgcqhkjOPQIBBgUrgQQAIwOBhgAEAKGEFVZUbQRPEpPmT2P5dCUy\r\n" \
"05S62qYfhyWPR68zua6GCFiNVBizrqWQmKo0CbKXxXNxR0MURiaCAs0Zya8Avxlw\r\n" \
"AeF4AGmaPkriL3miR9/1oTHau3BM+RpR0X3XlQ84r7Rz2fGJFgz6pCkWd4JiB12f\r\n" \
"uzqp8TabokI+NBpUZeD/BzcOMAoGCCqGSM49BAMCA0gAMEUCIQCAEzzH0sVbFnFO\r\n" \
"2+tI6vQnz0tfGLDud8DjD9i1bFsPIAIgR7swi5mtPYcqhO6dGsc3RxZGzrrjvxdk\r\n" \
"yoka1doWmfQ=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_8192                         \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICYjCCAUoCCQCm75s3Q5Y9tTANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwOTIzMTEwNzI1WhcNMjEwNjE5MTEwNzI1WjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MIGbMBAGByqGSM49\r\n" \
"AgEGBSuBBAAjA4GGAAQAoYQVVlRtBE8Sk+ZPY/l0JTLTlLraph+HJY9HrzO5roYI\r\n" \
"WI1UGLOupZCYqjQJspfFc3FHQxRGJoICzRnJrwC/GXAB4XgAaZo+SuIveaJH3/Wh\r\n" \
"Mdq7cEz5GlHRfdeVDzivtHPZ8YkWDPqkKRZ3gmIHXZ+7OqnxNpuiQj40GlRl4P8H\r\n" \
"Nw4wDQYJKoZIhvcNAQELBQADggEBADH8CT4CA0V1IeSZ2knmq06FCMxGJ8TYDG/4\r\n" \
"8Y0xYuoQqPBCXMoXnP8RAOFDAmEyzzv4pqA9p0LhZWXgfvKps5r5kh1T7VdmJaVD\r\n" \
"szUKNJkKU1fZ8oZzi5oM/LtO4cTmt5CLsQpUZ5DwdsTQ8hRvE3eCyv9ullb3OswJ\r\n" \
"4tBHZuqOA8EKKW4ThAQFZkKCVdlA11DTMxTbGDTv6/zv1CRbX9M8M/h9m30s2ekR\r\n" \
"prIjmCxsxwdhy61csX8XBoI1Kb6Ezn9NtkECMW1lkSCpnIT6SiXrsIgs6o0LoPEM\r\n" \
"yZV9hCKyDz3/v751Qu9MSoe0nWhvwnWP0vr7YQaT3cOs8RVcpi8=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_8192                               \
"-----BEGIN EC PRIVATE KEY-----\r\n" \
"MIHcAgEBBEIBYRfp7S6KzkimEHdPhQsNI5M0jCFdhiI3xJtoHWpqxA3PatGzqVui\r\n" \
"cC0VzPQVe08ULXbxCKSUOg6PGdRDMVKFVnOgBwYFK4EEACOhgYkDgYYABAChhBVW\r\n" \
"VG0ETxKT5k9j+XQlMtOUutqmH4clj0evM7muhghYjVQYs66lkJiqNAmyl8VzcUdD\r\n" \
"FEYmggLNGcmvAL8ZcAHheABpmj5K4i95okff9aEx2rtwTPkaUdF915UPOK+0c9nx\r\n" \
"iRYM+qQpFneCYgddn7s6qfE2m6JCPjQaVGXg/wc3Dg==\r\n" \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_8192                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"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\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_8192                                 \
"-----BEGIN DH PARAMETERS-----\r\n" \
"MIIILQKCBAEA35Fa3m+s9fj9tiQmgWX20opz63wLJWgdQ0Ov9gM6qthxyP7/ot+l\r\n" \
"qJGzBvDVGTmrR9UCWMPNmir3WTaylBwlnE7+0HLblGWWyeYIfl7YLrgC80Gys061\r\n" \
"f7jhGNNW22xfXg/2fpVzyf5f9Q/bDPp+HAaV27G3iy0L07C9NKww3SDTHjOLmXoZ\r\n" \
"tjPZetB02jn7Va0Cej1ffvYkfxbcGdcTUdwG1DrxWLGQv9h44JwYFXDISCV2P+Wx\r\n" \
"Ir0HsnsNEouffYqvCe5r9bM/7CyEjRn+0/bK+gJjTTTffVyFgYPb16PZOVVwY7kS\r\n" \
"clY+RrQIdLgpqIfN2/mJWHBCL2rsuGm9zwNy50GxYeCI8zoLBMtd/JEXphPi8rrP\r\n" \
"DZh4LfWXDYw3vjOYsGrUFNe/8Ezqu5W1lzhc72myzyLzF0IysoEAXy7RP5Mt3bx/\r\n" \
"B5OD5s87EF8DgWaqLzuAJlSQLyfzBwGXxe7osJIDCLsX9HELEkCq/bpF5J2ZN7eV\r\n" \
"TOjoD6zpfvrzL65QbQC9CsR6plmKijLbjROQ65dOnAQnYMBLh9Bh/TTdNgF/z/kw\r\n" \
"IELyM+plUCGQ6CnJ2erIvRg+Qnpll4gotLcdT4aBFZp/9GIGiWIg64saCzQxRarD\r\n" \
"nDed+MNzvCUMR8MiZE5VHYoK81Uezcan+halkQW9EprHCsVgSTUGPKKEG2bmpD5u\r\n" \
"64TuXxv66BCTv2fTLT3JYxpGBFItLoX3F9skON3EmH56rOX/3n+QLJzofCfw4WlR\r\n" \
"ThdkZQr8KqqWmVAC5guUixNotYpqfSJBNvQ72oLAorIUXkAvp2TItrZcMgYg5T9M\r\n" \
"IAoNxWg318Fbr7Zc9qLogOWojjc69zJJjvysGCIw8pcL+h2A+kPCAr2zpXy0PIKU\r\n" \
"0S2Kia3gBQBH+IMMcXP3aliZb+rCB4AUjqwWoiuDEMlJOImmS6fGvbvOv8GFRTwD\r\n" \
"6gzm9Lem+Xh2LaeZJz5sZRD0/cdt3B7L5zpPDZzN1Jm4Z15worIc6XNHBVAzHhrT\r\n" \
"OyFB13dK+n38dmopekqv38j+pRw/gRSBDmBOc1tYl4D7G4J6ASZuvo3TeI0yRlP0\r\n" \
"xeqv7UYj4HPuXOSjU2VPW70FsQEkMIb7X3cJzWsnYO4MgRmzQnSvfG38OwprSLBC\r\n" \
"2+q8f08ew/BWiKg17LSPkWLqU2o6o0sJ9yTcY3db15fyYIKaGNV4p6KFP1vNFcTd\r\n" \
"nPJ1zHnTnZldppPwgABkBy4DILpf5qGdQfpaB3T8ul2lDrt19keoCPeIcgi/LE7N\r\n" \
"Qui1+FdBsDhF0zc4CvluQyRrmTkQVGRBaw0ma+kxZu3CSetw6dUnZ784hVQJDu+G\r\n" \
"CJIphOa2Fxcjc2FhLZBABkgfO0tIvHZ9NQKCBAEAifaxPUR5JINRnEquArCJUnOO\r\n" \
"ddSIUkfEl5kF8TjEENA0h+oQ25xlhqZkHI3DAz6uqyV3gugReoEleMDxSH+xkL2f\r\n" \
"H0EZokMHi+lyJFQMO0dAXrmMe1sEcGckzYanuHd7G4dc+XdcsDXMydcgZdU1dAG+\r\n" \
"aODWVlJNBf59herjhdqtw43Fsi6pISm/AjZw6QH4bBa0aEuBGPF6E1uCkRILWpSL\r\n" \
"4CUVK0cciSWM0Ws4dW1gxz0aFKfN1DZJSQhJqWgoTdsLJqkZUGz2SDP0+M2zfYoX\r\n" \
"1kXhgj6JD8T14JoZ+e6i4TJVmxGNNknrGd/FG+2z91ObcjipmpHzHmTnJP9n9TcT\r\n" \
"Ke6HwnEzE1unq/zoXP+5may0F946zL/XjcY1CrWSkSRuZyj79AdJnIefHtf0vV8m\r\n" \
"5JzfAxtqXOgBs7CZP6mHmW5ZDw6XnnUXTzySaE4p4LXLd4c4XM0C1d4yMVqahl/J\r\n" \
"ELAhBDXjUHG46m89hFPu+uLoR7ixv/MI1zjdFi3WbLWvuDpCNaJzc3KheEPPIjKf\r\n" \
"1Ay5OqMV9BcAc9finElEcoQPEzQcbyjiCM3LlRVwXSWE6CN75v6/GpmE8G38v3UZ\r\n" \
"K7ppLdjtKtHnek1Y9nnZsK6vH0LSrolOpPVNmftYdK5sLBA2JgoMkdGl9eF4gblY\r\n" \
"GlvLOl6dVPFyUwUOfVKw0eXHlECcAn0Pg7dsqALpO8oL5aaoJ0RTkghXBx0l8gDy\r\n" \
"pGePDpjywpOjeYxUGzWxaZ0O66aIMBYN+Sahvq0N7+p7u06ZGw+1/LrSox9vNTpa\r\n" \
"MFYdm75ixiQElJWVKtRLy0PEwfCdm+eb88/aZgLerqbDFEEqF5QkCfk8LisFT+na\r\n" \
"z2vrG717bz47vhL4ch2pDxoKMO6r0LL2QWpSf9bC45U5u9P33kueDSJC/ZUjvawa\r\n" \
"Ev4T1LsftCsV7Gw6rsMdMHhr1Ar2j0k0kWOzD8e+CzMxxJbvdeYoK399U5ZRL+22\r\n" \
"aefzYcXVP8Dy3rc0V0RrXpetCSnbx/iwKBKfEKSlvEhSXg11DicsXJuLEu7sEvhN\r\n" \
"1ntvDJ7Pv/JZkNyIOCaM+K0vJg0t0rZa7Bm6J+WzDX3R0YOdj2qihvrFw6aBb7Ez\r\n" \
"bNEKEzfGziq02vJMv5H/shze9U/BAmDnPkgvtcY/MABNTipvblnecWFSIL6s77YH\r\n" \
"BPrduTWTexqIgd3x0KqEER2/FAycQvQ2h/xbkg0OIaQbR/Hv4Ev2pXYbnyTPt9GF\r\n" \
"AbhL/0U5oqdmajZ00vKyYk591WwkVsEGSDjqxRKbPxgVmEfYY0/mzpKu+TJ+DFM8\r\n" \
"KMWbuI0HWGmzbcrpvY0B6uZRWddEky/9fhYMNy9fJhpBGJdZN35uVievIbXvqgIh\r\n" \
"AL3f4kokQfJbevuMd1rWG/Sl2vP6ZfJrgLdF025D/dKD\r\n" \
"-----END DH PARAMETERS-----\r\n"

/* ---- END RSA_8192 ---- */

/* --- BEGIN RSA_7680 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_7680                              \
"-----BEGIN CERTIFICATE-----\r\n" \
"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\r\n" \
"gQkl9IsPNL3zaN9tsnI=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_7680                                \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIB8jCCAXigAwIBAgIJAIcHjmLf87Z9MAoGCCqGSM49BAMCMD4xCzAJBgNVBAYT\r\n" \
"Ak5MMREwDwYDVQQKEwhQb2xhclNTTDEcMBoGA1UEAxMTUG9sYXJzc2wgVGVzdCBF\r\n" \
"QyBDQTAeFw0xODA2MDgxMTA2MTlaFw0yNzA3MTYxMTA2MTlaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwdjAQBgcq\r\n" \
"hkjOPQIBBgUrgQQAIgNiAAR6pGFQHnYqwhqvHm2WxtE99RTF4qiqPKEFB0GgmCJ6\r\n" \
"d+tuxPTgta2Hdqoq2pktm4D91uB4kocnFPeJtfDWfpw+ZRSSIFcvtJ16NsOmdBBL\r\n" \
"zbpWT0cZqetPw99aq/FrmrGjTTBLMB0GA1UdDgQWBBRmSRRhU47fKvvgsgxH01se\r\n" \
"feWLhDAJBgNVHRMEAjAAMB8GA1UdIwQYMBaAFJ1tICRJAT8ry3i1Gbx+JMnb+zZ8\r\n" \
"MAoGCCqGSM49BAMCA2gAMGUCMGO9YN/r2BTOlO772a+FSBdZp06VvDv3XAoGKTqi\r\n" \
"CGXPzx01H6pOXA9EmcheAUvPzQIxAPzpFRRqlIv5iv9ufs+y7GqriixJ2jZs5lBQ\r\n" \
"KSnm5Z4dVF+0KrbLKBF5NBGoiXJhYg==\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_7680                         \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICkDCCAXigAwIBAgIJAIcHjmLf87Z8MA0GCSqGSIb3DQEBCwUAMDsxCzAJBgNV\r\n" \
"BAYTAk5MMREwDwYDVQQKDAhQb2xhclNTTDEZMBcGA1UEAwwQUG9sYXJTU0wgVGVz\r\n" \
"dCBDQTAeFw0xODA2MDgxMTA2MTlaFw0yNzA3MTYxMTA2MTlaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwdjAQBgcq\r\n" \
"hkjOPQIBBgUrgQQAIgNiAAR6pGFQHnYqwhqvHm2WxtE99RTF4qiqPKEFB0GgmCJ6\r\n" \
"d+tuxPTgta2Hdqoq2pktm4D91uB4kocnFPeJtfDWfpw+ZRSSIFcvtJ16NsOmdBBL\r\n" \
"zbpWT0cZqetPw99aq/FrmrGjTTBLMB0GA1UdDgQWBBRmSRRhU47fKvvgsgxH01se\r\n" \
"feWLhDAJBgNVHRMEAjAAMB8GA1UdIwQYMBaAFLRa5KWz3tJS9rnVppUP6z68x/3/\r\n" \
"MA0GCSqGSIb3DQEBCwUAA4IBAQBBhE+cA3cBm1GEfP9iixMdTxM/+ry78jcMMEIk\r\n" \
"6Z0UlzI0vulUtR705FM3K+iv9T+FZzYqJvLU7izsVfdStifIiCT2OJgISK2SqLtG\r\n" \
"dHj6pv4BwdCvLit1YL1XJt989J9tpOUxSVsZFDUUMd4wCVBA732G64Q+3qPGV1EO\r\n" \
"eWmNTzX8M+FbRGw8bJtIJXIHoAweQxvz55oWsPtUyUKhPDZmZC93ZfcfikkN2su4\r\n" \
"Zm3KZY+ue0tohJ7hGt0dItn7XLu8mffp4C+g+sbDu+tio93bqsAOCeHijR3X6tiy\r\n" \
"kLK/gVBuk3zAs2cIH3uOBBzGlW/hCFiBlcyOGvNaR4i4tG2j\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_7680                               \
"-----BEGIN EC PRIVATE KEY-----\r\n" \
"MIGkAgEBBDCBKO/jeTdhO/OFmcloGdtCkhTnPgcniSwjaW78wR5VaInVoe84InsQ\r\n" \
"3jBy6SQd9FKgBwYFK4EEACKhZANiAAR6pGFQHnYqwhqvHm2WxtE99RTF4qiqPKEF\r\n" \
"B0GgmCJ6d+tuxPTgta2Hdqoq2pktm4D91uB4kocnFPeJtfDWfpw+ZRSSIFcvtJ16\r\n" \
"NsOmdBBLzbpWT0cZqetPw99aq/FrmrE=\r\n" \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_7680                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"MIIRCAIBAAKCA8EAu+Qr3X0RthiNNeQhWwQ2CHpVMOabBV8PgZuWFvNxW4h01TCY\r\n" \
"3NCHXapuVsRBHbhH5vJw0rzCGzUZ4JM47OKmefSgQ1ULof3g5dRZnh8kGHcfrfAV\r\n" \
"Q1a894aUZj9AxNFTof0wCXVHye48lU1qyUWMrnT+6r1xE5sYPY+tPemQA6hvVwjf\r\n" \
"Gwv5KByETJT/TYxo/DPPcT76x6BcFLfs4igZeacNP5jFfUlo5fPw//KBwoIICpKn\r\n" \
"DLRjSm6V5+o/H+Q70OKywHXOiD5EVnxKhBEFWSxE8js1rcoc4BBDmhOt0W936xen\r\n" \
"NRJm9UQZg5B/8kt3NTt0BmC5L8P1MVBFg0FSCpHMGJs4aimIoOHLnlr+uPtjslCn\r\n" \
"BBwZ36RpCB72erQBMLhjn7xanfvbBcJ3lPt4fm/biNN5MQUBkhNNq2uFHhUx4690\r\n" \
"InHoFw/vL0R7FL14lTAWo2VUQ6OP5OLAey1qojUNHlgin0xzgZka46pDZH5FLBOU\r\n" \
"pzaPjadSCOptZCOAS2iVHnERtmGi2wBdrxmYo+8+3mYrwpjza9M70N36H0K/YyMu\r\n" \
"H1pJ5VFDavk4cAUmiyirZTDfibYhUPpiTNhZjDkwc+cWuJNtDIZ5fLT92lug+7dr\r\n" \
"2vNsR2o2V7OGggEw91GYI9aR/MtQhEOCeTgB7qptQVtsh+rOcyulIYr6g6KfddJ4\r\n" \
"AmDY+LNKKH0Yyrtm1epdDTbflX93P47HRdKWl0uY88PSFPl0o58OoWKCErEnobqE\r\n" \
"SWOBwsBIOPYFailr0cU4wSt75Ld7RuubpXGD0YziYsY+IH0lJMnq+t2jFCV2JI1V\r\n" \
"CG8MrO5WtllJgQgQ7YVmcCobAKDAwnXyq6tcJlsqiQHqM6dyFmCJRqJB2Nl23iGa\r\n" \
"Uw9lfvq3DNrZxlrHa7RPShYT6pahms00Vk2AVW+CtxK5qQyYYkOHyKgT9XIbRaks\r\n" \
"wRt1kCiKHVaGmpEPqd9o4izgAatiXsYkzs3tj8ZnrgrY3XefNVuYorCMl74ectwJ\r\n" \
"E5VUcGl5VV1MWsY3PnS5NyrTEFYq8xdcYBT0NSjD/xfVDZ4i+dt9ZYdP5UjX7fGq\r\n" \
"IdoX09jPbvF/PiSQTVF8xHzb/tXv6mcLHVyOmN5rwmtn1ZXqka5w/8Vp9ouraawl\r\n" \
"Pwr1hsBAAcAeA7uurAxfTINbS2u/flZEJCB6vOAhbkRj1J6YyBqyx3+yrZZda9kG\r\n" \
"DN4AlgGpIr7JCbg8+Aaa5XVBVWbjuVvHn39b3ncJUbcjr1qEa6+b3PMib9NFSa1Z\r\n" \
"KdbF2gu5SqY6HJwDAgMBAAECggPAUSbh0047ohzEkOwxg/AzrkG4HeDcP9upBN/A\r\n" \
"WbVX1qL/Yz0UKPtgHBKKiatGPKHlXFiGZl7kr3+l55tu0NGr+ayws6Q92/+dbWbk\r\n" \
"NilZG8AHzMaPSIBkKbzUx7y2KswGhUanws4G7a6aOBox7zC87HTXzWd5OXCZba1q\r\n" \
"s/z3GL1dKYhJZJMtUCfQ9Iq+Ii5tAdEW3eDHzAT1AHXYOG39Ys/GJxvC4LQePIO6\r\n" \
"KbICXZJwCrEAuboH0JQm5v4DubCILVZcwkefprTOK1SPkq8PUk6OkNkF/EP5aMVd\r\n" \
"jWTGhFjSwJV8wK1sDq8VHgABYxM5L6K4IDESixDmDCCRhXlnB+2k61PPb/r0ahhc\r\n" \
"K889iYP6sX+oQ1wnyLJoMvu8lY69nN9nGAzwTqADH1+46n4asvF5LoW4KHXzEbaI\r\n" \
"q2tLGY0p+R9E18O+7IcTVaUMTA7xz+3vOS+Az54Lfl55qDobfmfPfLWwboFEukr4\r\n" \
"lDBr3zGyirECWZ51LkeAZR1rlf7HYMqQ7Y8EiXNuNYzY6dHyXYvt6XzTlb8eFAou\r\n" \
"Ia5eY7Yel6EQQLZsiEErDz8JI0j2NtCgBpqvUfl6NlGOt4YSV0A0Lzs2Uw5J4UkL\r\n" \
"m9NIeVFuHIpCaVUOBWJYilSd2fTNBPFXhjf5CSW0mhQD0E5710ZqzYUItRe5QYdf\r\n" \
"6Yp6vUtuiRplh5od9S/ykewrGPbee131ELrkk4qH20M7A9uuB/Xzhmot41WAsOye\r\n" \
"4N6pczxBSLmG4FP4syty17SYP6rwgcExWIMwbnKOwsFj9xqn092y3ktsOmzZtjr9\r\n" \
"RBJ85+fvqCr4rzAsLQ6yADOUxi9XjYf6GVxWCEdZvOkIgY1o+RyyLr5NCPxSJIgc\r\n" \
"1/RMrIERlMer4C/9sNtFgGcBKSKpS45A2vhyYsbVOhIBDyOn2962k4JqWFBQqRan\r\n" \
"fzL/3G2kpNx3VicaFzreGLLgywzkXaXysaQrpHVm7eFLqeQ4B4lxAFpEoy0y1GPv\r\n" \
"B2khR3mE695V2adj9aaqmcy78iKq6kjzhDjMWonWDeYUctuEcw9Ijob3Jj3Ds/FU\r\n" \
"A8fTuqtBOQBwzc8vN/Fc8Pr+I3mzt7xQEm52hPlVa2GZkl0BO0JJgiiMe/c8xN3f\r\n" \
"VxtQy3XZjAQbQ3UuQ6DV2OnaN+qwNw5TAhAWnhGysGEs8HsxNHKjzaIkcGy/YA9c\r\n" \
"77q3qFuxe9tzZnVZjoCEPYTLZlA0QvMF6nGN5PlpEWLFLQZCgjT3V5+5yp8b5F6Y\r\n" \
"l6gBtpTfuEQ0ZtrJzlKswVAbFOyRAoIB4QDzBqTd4Bw2BWD5LZvqwV6vuQDZEshH\r\n" \
"KsDST+XxR+I3mQmpIEl0ZccCWsS47DPs19FDo1yZYLoS+aoI8h20asPoTllzDkdE\r\n" \
"mCxHHHxIZRH/Nx5pnCw4rhxTvBEKc9Kc+nlZWzoa7wLfQKNVGltI1i9kWYQ27ahM\r\n" \
"lxxn9O2qwcyy7tyJHWRRuoT3eBg9aiEURDywoQfshbEmSxjGZeIttYTYatZNmG8h\r\n" \
"JwYe1aYhoYLvIsw5Lb4/eeqsGD3qRGwfuSipAzpq9tEgXnxHbStj9BctVpydvTO3\r\n" \
"yiEKYp7Z41Vi+VKV+7l0oq8gly59MwRwQddYz7OdWKmOsCw/Y45ZczEdfcc3gjt4\r\n" \
"BbPkJDWcai/hj3iOAtmnKSqU248S8ws95dy1hw7q0eawpY0BvedVqNavmlsK8hEJ\r\n" \
"mHou9xsmNI2y3BO+J9ary6BuQp+Ekufd4Kh/3koUhbY4O/nZj3FBcssbE0zVeF/x\r\n" \
"DwIjrnJbI/nAjYkml59VNTCLbNtspa9W5RX1/HsIE+Uls+KLoxbWIx3CYA+755CF\r\n" \
"2YN28KrI5Rlt6VSfSaqWpcdPmqE4JEXFgtIgR9s50AA9ICdZltB8Tm6MvrbW6DYg\r\n" \
"c6Tu+miAVIA3AL5gs+FOLHH2oJNWweMvEf8CggHhAMXsBSFSJ7LHebhDjkix9xFp\r\n" \
"wzG/8sD9kUekeY8z4V2eEkbRagcxHwc0ZtBd0n9FUaYPywzl2mwn5Ns0CeUg+R+2\r\n" \
"zL+7BSp2xWHMSD7bYAhtdcr3zVAwnug5GthqJEribuRGliOsA1yoYDCeIMssXo0Y\r\n" \
"GkAxRCS+Ck0vr/67nkkA/bSXkD+tm69bvEjgyYTgER1CpbuaSig1jL3efYodwa88\r\n" \
"weMHjdqmz/xxK/dkg4EqwTzYNxjGwLCwh2Q02OllWM/ma2AmgH7H+1pvuaNsuEKJ\r\n" \
"a6QUFP5+fdefWoJA/+lMg0cjALSVIo4gv3UUkoR7Ld/9fYZ2bsUE6YIW6VhcQZg8\r\n" \
"uFKwlJeoq/DDl6qoUhtJgVNRmZBxUnSzOnnFPU5zPLL3WBh3z//pevsiRHdCI6X4\r\n" \
"87VwzDwfeLL4bPtLrClIEROcOlNYfc7RTxifB2QZ8tK/3/tsgyIcMQa9ZqJQy/jn\r\n" \
"rMSYKzbGm3tzoTEBhdrzJTGJtDRj0Tz1EYri36xXePyw5Ij/SpumPQyRKNcKpIUc\r\n" \
"PS2K6b/0PZeAe6hc/w57eX3ZuVJKPUF2uYEkFQKEOMO/B8GSsWFuPV7rtHLfwIwP\r\n" \
"BbDPPaF8+yFgfFOf3o7vKFqDhzSKCNlgFjK41ZIt/QKCAeEAovJjfLkVcUst+CUS\r\n" \
"k9bPy/a5kNK9IqqR2vHjdWIDVc/w4EtbtQXA591AZdVKA5W5JCbWoahvWuW3koP0\r\n" \
"UtH7RTmzVCfQtTdrCMsasdfCt2KXq6whImframGA84cxQjvXPYijbweu304RtbAU\r\n" \
"YMPrxtcWhVXYMHJpg3KAIKwMujTZ/b2NVBdBrEQDzLnqMBKIts1h6L7DRq+3jt8l\r\n" \
"RgydZBZOVnzMlmf5/Ja363jFt92XHQeEtj7ikD041mjGLocRsjEN7EZNdeykW6fh\r\n" \
"HgW9vJKENGd109ddS/9QDzwUNmaBbzr24DNsROfZLe0VHsemwk+RWQDnv1p0cJQq\r\n" \
"D+PinKmG97sEcLcyJNf6ckPoks6FwII8uY4qlOCaD9SSRxBmafiCkgPnL63w26gf\r\n" \
"AhpQyDEwtigUMGDiG7dnprg6AiD5w9gmYc4IZaWaG2P8v5IwqHu9JAF7aj0cizlY\r\n" \
"cM+tSxwnukIZ4iF0B8ShvGZkwSylNxEWriUZxYJZpYF6DUNQ9Dwzqfjc/eidD49s\r\n" \
"cmvdOkT6h7z99CEhupAnkse5wy5dpOfZz2ScPM2rJ196wLG0fhxv61WBs3ppp/It\r\n" \
"HAvip8///Bx6nkur3OhdRR5jUX3YKDKz8JxwVTLZV6Rs1VS1AoIB4BZLLZDBRkN3\r\n" \
"AJjm0yIRGblWZmw2KMvgQ/sD5cVhnKME6R4c/Ipu2AXhuysBRnKbhkTkRoTfZykD\r\n" \
"nV2rkOnEOwt9dbarBDvyQO1xKzoZT8njOn9wRiogL+YMeJ+j5Q6iTsdbxBGkkIRh\r\n" \
"WuRfC2aXStctvdc5NWnGFjb3hiV1ULD8cZdj8xWZIo4wERdMaqaS7pqTJUPqbyv0\r\n" \
"TDQe2ZkzHNv2RgiikzHr1EWlIcSuB7oG7NlDqYEa8h105Os+oKg5iDVyyOl9rL+b\r\n" \
"Gw7mwsxLtL2Z6QwETxETgm1FP9aoJ6tJuQfMQ4oTul60BZzUgmR104cFcJwyvutm\r\n" \
"UD8dAY+4ZJMXU9PMnBAxKZznCzBn4Ue9kdmmuVtxyE3o2k9ZDjzF8jJedgfbhwxW\r\n" \
"aknbZEbipk1Nq3XmjLrA+MGABhaQQYYs3e+Ni2xT7WfcX8JwN07pNVbT0hDp+iNf\r\n" \
"dY5Cy0rBOxiAUA+c7FExMdZIAgIZH9C3zpqz3h6Al9L778vrHjK1b6VW74cW6np5\r\n" \
"0SqXNzhxtHJh6eo1WXsLsdxc1pDyWLBy7A5m9d71Cc1T6DVJsSwlZJd37xG4yk4l\r\n" \
"Mrh8aEkANxoPnx55WYHVKBxsV9S7j0AeZDc91X7vhWumzRlNhJEAqQKCAeBoRM+x\r\n" \
"C1zTdUB/nOXLpG4SGiCoCbyg4XVJqLwml1BpEawlC0JoPTaRaq1dy5HDJ4lnm9ed\r\n" \
"RjZK+LW4uS3ioJ5Kn8O2sZi5jowQtxymCQozA6BRCA41WMTbqLrYNKvEiYajBwAW\r\n" \
"0BsTyS1IhzaYuhYQnQNyhwl0y7BqbtUgxIL3m23e2mR4SlmIw8HlouyFGEx/TXls\r\n" \
"als3xNsE4i95jEcEa7/J5F3s/gPBIKYUGqBOUbCfw+vTa9wf/uBwXSsLRDaQxowB\r\n" \
"oRbmczfjRgUb01YxX3eqXcSzqDcbfE3sYEb6nrF9xOSykFbRZ89i8OpfERY++m+l\r\n" \
"2B9sfjqrH7F70qyJn9yGQSz33QWUr8XLrKB17wx1ffr7Lxs7oFYgy0AqRXgKPVMs\r\n" \
"tNS/Cw5TirFNZynmx3R7bYK1kN+XoVgIGodKTE4uwccnbjOPHBMnJdvqTAY7ETJy\r\n" \
"5i4qYBdaIc9hc5v0OoI0WIuPkMIpkGstjxJK5fU8AcYYa7CJwqj/O9UTssAbg2G3\r\n" \
"nnArlHZGm81Q95N/4e8pGU04zpuXEqfBJWqHEXIGyl8v9EIVxSrCY5P730fm6dPq\r\n" \
"4Pd8+l9gyH5v5iMIecr/lihdEIRwx2Q1AZdRNG6u44F9+n4OZyHrOBQY4f0=\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_7680                                 \
"-----BEGIN DH PARAMETERS-----\r\n"                                    \
"MIIDyAKCA8EAybqOCygCkZwwTYVKCo9ShlZ2qVIGp0GP7TU02xLqTkL6uBCa7JOj\r\n" \
"aWsF77Lv/zjgeMt0dIjLC6jaqzsquTjhO8AEqk/f9upcrU2CD6fPQsSYJkuSnYpY\r\n" \
"fo66Iv/NqQAqUHmjrnjsm0TGGL5r//lghCiQKpb9N6YxxsNwH7WfS5Mpkn+3/tJE\r\n" \
"X2WA8gbRjZT7pGJzSauzvg7NdOiuDVSkb/TD/n0caojd2u2PfBJwn9r4o0ITmcAJ\r\n" \
"A5gVOjdGavuF1qje1WejTJT/iBdG3sydEKl5djvtXpF3kB1kk4FPaM1KbACN/i/v\r\n" \
"K8wgYhK7sjLSMIikUlgXcADqA5mFP3oPKF213/R0OlERMm1UayTk3SolC4HhKPTL\r\n" \
"FwSjkY3OMO3hzYrqCdXOt2O0Z9R/SgyYzScE5zH0BQCsfQjRKqxVRE+T68cjIx9u\r\n" \
"DhKLBc9fS6HCBRVDltLPvstrkjz+YljWmkWO9n451YinZ//ypcew5BIsIJmYB2wQ\r\n" \
"UvXDvUC5DRnC4h8lEqe8bjUgPvbIR4VPYBFAEAAhRU7rPMLlMsk4PDZkBdi/ikjf\r\n" \
"BTO72anA0KRjcscTbrvbsVLoLDmDenwB/HZusAv5Z72qhT51keCM+Cu4xpEK8+VW\r\n" \
"/cO7Za9mYaTspfxWAyF5A0ChzzcRgIUY0rKlPPUpf5sbQK2gEORF0pS4v+TeBCsR\r\n" \
"7dZIssL/94YZQNCVu2fWxd8z+0QZcn7M7RrlTRKKGSH+CCN8izvVxBPknxAu95yV\r\n" \
"1IUV0uZZDrNdGi8HLJNPsSYGjvFz5jFSj9vsVlQWp3vzl2tGVcXbSu2YxhCM0LkV\r\n" \
"9vQKU4HpM3zt4swc8VGFREzH6EyqK1CLc/g0i5iCpPEXNEYV00PVhhSAxizOTy5P\r\n" \
"Chdc6l+eY7aeKqRZOTIIzDjQ8Savb+lGTh2SZ4SxjB+Eb79ShMcJ72cfyEivSA8w\r\n" \
"AKK8cUxBnJe/PyOTGM9j+aP3vnHY5OX6894O1/x7Kxm+4WbENEQWN+2h066uDpLl\r\n" \
"5RcL1uHTOLrVLuPD7BSxutaWfDkURCVkVoBxXqIbeFq4Ypd2SO3WRx+tH4ZiN0zG\r\n" \
"qubA/JZZgZJwTKZXtp6L4hf541mNT8f99BKdsegR9ME+azeqF6f98dFJcakYcIZm\r\n" \
"rkT5XpDzSKbU1FwwTYlDivg/6n5N1yMBd7n15N32o6y5BeA8uI4YRA16lCI/kqoC\r\n" \
"7qMlQB23VTMFENzlwBu1UJ4uUAmgxrCJhsvaFyePIGNeslje6u2VTIRV3F2UQNK8\r\n" \
"tdgLyCKYgeRLAgEC\r\n" \
"-----END DH PARAMETERS-----\r\n"


/* ---- END RSA_7680 ---- */

/* --- BEGIN RSA_15360 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_15360                              \
"-----BEGIN CERTIFICATE-----\r\n"                                       \
"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\r\n" \
"8Xewx7ywhzJwfzX2Umw=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_15360                       \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICFzCCAZ6gAwIBAgIJAMq+Pa7RgPeiMAoGCCqGSM49BAMCMD4xCzAJBgNVBAYT\r\n" \
"Ak5MMREwDwYDVQQKEwhQb2xhclNTTDEcMBoGA1UEAxMTUG9sYXJzc2wgVGVzdCBF\r\n" \
"QyBDQTAeFw0xODA2MDQxNzA0NDdaFw0yNzA3MTIxNzA0NDdaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwgZswEAYH\r\n" \
"KoZIzj0CAQYFK4EEACMDgYYABAFEkSoVTXwS3phqDKmqFRAB6YlTuYM5XJa5bfRy\r\n" \
"jMlawTGF2JT5fFDwGU4NA1etmF8WDEnjzz7pmzCAtpnRQVVzlwB7WglEbNXJv4zZ\r\n" \
"f/Jt9nOfnzoQVPOCczQYshsQjR2XDsZGEIXDQrfJvhObSRr/Hk5J2QcWYfOL3UqC\r\n" \
"MEs2fdX9oKNNMEswHQYDVR0OBBYEFC1qjpE1Y7NA7o5UfNdZ0eC9dx/RMAkGA1Ud\r\n" \
"EwQCMAAwHwYDVR0jBBgwFoAUnW0gJEkBPyvLeLUZvH4kydv7NnwwCgYIKoZIzj0E\r\n" \
"AwIDZwAwZAIwSHyGIyCCAkS/vd1VjiHdV7lEzNQ+kZhoFXCvpFTjs0/OpEUMQyAF\r\n" \
"vVnriH2XaWS9AjADGTh3Q4GDlpNXTDFDbFrWIu3zzpt0gvfGxOj8b/jBQN8FiLia\r\n" \
"d0uWfqatEBUrI2Y=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_15360                         \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIICtjCCAZ6gAwIBAgIJAMq+Pa7RgPehMA0GCSqGSIb3DQEBCwUAMDsxCzAJBgNV\r\n" \
"BAYTAk5MMREwDwYDVQQKDAhQb2xhclNTTDEZMBcGA1UEAwwQUG9sYXJTU0wgVGVz\r\n" \
"dCBDQTAeFw0xODA2MDQxNzA0NDdaFw0yNzA3MTIxNzA0NDdaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwgZswEAYH\r\n" \
"KoZIzj0CAQYFK4EEACMDgYYABAFEkSoVTXwS3phqDKmqFRAB6YlTuYM5XJa5bfRy\r\n" \
"jMlawTGF2JT5fFDwGU4NA1etmF8WDEnjzz7pmzCAtpnRQVVzlwB7WglEbNXJv4zZ\r\n" \
"f/Jt9nOfnzoQVPOCczQYshsQjR2XDsZGEIXDQrfJvhObSRr/Hk5J2QcWYfOL3UqC\r\n" \
"MEs2fdX9oKNNMEswHQYDVR0OBBYEFC1qjpE1Y7NA7o5UfNdZ0eC9dx/RMAkGA1Ud\r\n" \
"EwQCMAAwHwYDVR0jBBgwFoAUtFrkpbPe0lL2udWmlQ/rPrzH/f8wDQYJKoZIhvcN\r\n" \
"AQELBQADggEBALWdhiEsV8N13QWbZfXt0F/70xuGZDVlUGH0LMkyKomLOScEu5E+\r\n" \
"CKj6fZqomB6IFeMxIIRoKfUP9S3tQruFipCtK6kZvbWGFio5zR44m4lZ4LNzrAIR\r\n" \
"wRpeLCeVrqpD+wUGfQc6t323KBbg6TpaHv7jF6fq8kLkIShvX3dIU68h178bZNnq\r\n" \
"wRGkQ1G10Fr2Q706HZwqaqKb18gjUpHUR7uNYoM2/fz4EbfrSOC6Uh6IH1ORwmLZ\r\n" \
"w3+NJJOUYFDhEu/PZtYuHT8e9b+OBQcrBRx78sdbEGxprTrZ6HG5+YSks8BewQWe\r\n" \
"3dfky4Vx7O0aNGUJoghPIky2WU02Y5qID/I=\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_15360                               \
"-----BEGIN EC PRIVATE KEY-----\r\n" \
"MIHcAgEBBEIB2yPT3tC7QtdjpwQkk+G2ntTXalqY+1C2mh635bQOtzNPwxvhkbAc\r\n" \
"DsmMcYZ1ygEA/FDEVIHqqFTlF6RwA9NFyA+gBwYFK4EEACOhgYkDgYYABAFEkSoV\r\n" \
"TXwS3phqDKmqFRAB6YlTuYM5XJa5bfRyjMlawTGF2JT5fFDwGU4NA1etmF8WDEnj\r\n" \
"zz7pmzCAtpnRQVVzlwB7WglEbNXJv4zZf/Jt9nOfnzoQVPOCczQYshsQjR2XDsZG\r\n" \
"EIXDQrfJvhObSRr/Hk5J2QcWYfOL3UqCMEs2fdX9oA==\r\n" \
"-----END EC PRIVATE KEY-----\r\n"


#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_15360                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"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\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_15360                                \
"-----BEGIN DH PARAMETERS-----\r\n"                              \
"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\r\n" \
"GGkIFZnRVoDWrbyqP0k3BUMCV+zi/zFBuw509pGP2Q/K+wwIXFjuX+9KfQrA75X8\r\n" \
"h1F+/+4imfVCJMuLiItCk8R0OszHQaTZ4e7ReXmlxPGZY0jXUvLJkb1YsVhFKoZQ\r\n" \
"FKGWygXK6BHcWnS3nSI1lHyESunkysEM89poGomFYvNllN9zxuxnd/GXHBHoLJHp\r\n" \
"Z/5e0gTJO+5TsqJ19UcJ64ppAgoN1gL1umbAzlvFZMgLO+LK6pFZG8x0q6qmaK8Z\r\n" \
"wsXmw3V+3zY1IiUUI6+bbZRKdbj1VnmAdKWfkSuaC3keEzaCq/4tDPJHV/tnVn0J\r\n" \
"vX9sPPW8GhPRiLLF+OvHqRMQFIWcEs0SIVqr7kjnNsa/yWU09qFxj2jj43dzUmz3\r\n" \
"kS2w2p4V08Mfoehi+fDmgTRswE/rXz3jbBDQIh4e8ULFnLrskA/5barIOtqzWx+v\r\n" \
"3rmMC147R57kdHs4UeDQQzMsYCufuXo/qquEngfSQny+kjvPi4Gg5YNQ8mxV/rKN\r\n" \
"FkHYc9hqqA+DGE9OZC37SWsMei8TN6UlA1lQzGuTtfLNogLBtMMio1+vkWMvkkAX\r\n" \
"jrt7jFbrRP1kZGkzrYlfeU9bpTaaBoM2cqOJRApJlA51pIP+7b0HjS1C7Y6sY4rt\r\n" \
"S2IAbfJXr1qO5SuMjpmQntFiE3l5gp0BPAeMny+EDdZTw9lWRmky6REwMNAue022\r\n" \
"dTionw/k0OoofoIKcZ/3nyzSXhP7iTPVHNsqJooUIRQPMdM0j7zzxpcniu30rDL6\r\n" \
"UKU/ws3W7q9qq9WusAIhAIAbar+Qxe8BcF8gJHRJo/e2PDGP1mO1feZYqrrGjavN\r\n" \
"-----END DH PARAMETERS-----\r\n"

/* ---- END RSA_15360 ---- */


#endif //MBED_TLS_SECURITY_LEVEL_H
