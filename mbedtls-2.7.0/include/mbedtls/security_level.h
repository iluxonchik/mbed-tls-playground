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

#define USE_RSA_2048
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

#define PSK_112_BIT_RSA_2048 "52126f1e258dba64e31d1572174b"
#define PSK_127_BIT_RSA_3072 "2b88bcc7caec33b6cf61cdf06887d683"
#define PSK_192_BIT_RSA_7680 "ed78bd38062e4e033136da8cc6022d7129bdd09ce06b5d63"
#define PSK_256_BIT_RSA_15360 "71bc53a3beeaa416a4050653cec13d288e3eb692959cd0828499b702739e482c"

/* --- BEGIN RSA_2048 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_2048                              \
"-----BEGIN CERTIFICATE-----\r\n"                                      \
"MIIC6jCCAdICCQCPCB51YJYRGDANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJO\r\n" \
"TDERMA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0Ew\r\n" \
"HhcNMTgwNzMxMTcwNzMxWhcNMjcwOTA3MTcwNzMxWjAzMQswCQYDVQQGEwJOTDEQ\r\n" \
"MA4GA1UECgwHbWJlZFRMUzESMBAGA1UEAwwJbG9jYWxob3N0MIIBIjANBgkqhkiG\r\n" \
"9w0BAQEFAAOCAQ8AMIIBCgKCAQEAzCwMKeoKRRO+/SkbChwRcbjd1uaQqgwrm0zY\r\n" \
"APCj4rylsjZkLdCEtrveMqbO7MT+0e78UQT0pu2dV0mwTxwmihCxFXXv6RB8HIWo\r\n" \
"vNfgJB3AjOq3vsTmWYF62pjwo7+KuMuW9PK6ddk8fk/CYbl+AJ0a/5lPgeqkMzw3\r\n" \
"e+wnpsaLstpBloxYz9R7XmloQTZxoys3D3RCCftUv0K24Uu16I67FwwjPv0dABxW\r\n" \
"QswGBnhHhU/YmM412qVNIzNMu7Gir/PTm3hDZcjBnLmGfHWsP7jbsi0JwIssfozC\r\n" \
"dLQYmZQXc5azk1vQkBlufFSDKCKZBm6FRePWl3jrWTpfyJR8swIDAQABMA0GCSqG\r\n" \
"SIb3DQEBCwUAA4IBAQC1yE6jpRlAHQ1K9VbmyywK5ex5CRPoHfOvs71aJV/LrZf6\r\n" \
"SH47xyzkOREgCx3GydNDnbHAbLDboMTzOurYTlVqjQ1lbfC10iAb+snw8tojW4rR\r\n" \
"+wJwSDGj3huHqx4cPZB3dcrKIPk6Yjw3G0msUvHJ2yElLuIYlSIORs0XFgDYkt2W\r\n" \
"DvsG23KqENZcJaqV2/aABwhNObqQqcKWlfeGOBZZuNtbC9G3sZ5HJhQYRLjAGSav\r\n" \
"Cb+fgf9Lgq9VVsy2P1otP91OVMEcU4VvX0u6PqYCPnP65z86NK5vH2TYaTUYD+CA\r\n" \
"Y+37pT9ftzkyxLlUTf92Eo1JRdVV5VM2laB+lknI\r\n"                         \
"-----END CERTIFICATE-----\r\n"


#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_2048                        \
"-----BEGIN CERTIFICATE-----\r\n" \
"MIIB1TCCAVugAwIBAgIJAI8IHnVglhEaMAoGCCqGSM49BAMCMD4xCzAJBgNVBAYT\r\n" \
"Ak5MMREwDwYDVQQKEwhQb2xhclNTTDEcMBoGA1UEAxMTUG9sYXJzc2wgVGVzdCBF\r\n" \
"QyBDQTAeFw0xODA3MzExNzA3MzFaFw0yNzA5MDcxNzA3MzFaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwWTATBgcq\r\n" \
"hkjOPQIBBggqhkjOPQMBBwNCAATZ02ynxofvB2Ctqs273fSx4709TCopET5XDw4v\r\n" \
"BEdExNKRkfX7vyNWXWdyRWDi2BWWrK5LP8jZ51/qqgruoNeto00wSzAdBgNVHQ4E\r\n" \
"FgQUWAmoQppiCo35XT8WwagMkQ6TB3EwCQYDVR0TBAIwADAfBgNVHSMEGDAWgBSd\r\n" \
"bSAkSQE/K8t4tRm8fiTJ2/s2fDAKBggqhkjOPQQDAgNoADBlAjEA8YaOz6Eveizv\r\n" \
"JI5bNDUcsFIax8XEQLn6ML1rawIankuJ0XLJO5J4XvvnyrpytkRpAjA2KbFT/HyE\r\n" \
"wsFe4YoMemdw98I1gyC/xK8XQv1Xy4P90vI91zyZbJDGBMs9/EQzk8U=\r\n" \
"-----END CERTIFICATE-----\r\n"


#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_2048                         \
"-----BEGIN CERTIFICATE-----\r\n"                                      \
"MIICczCCAVugAwIBAgIJAI8IHnVglhEZMA0GCSqGSIb3DQEBCwUAMDsxCzAJBgNV\r\n" \
"BAYTAk5MMREwDwYDVQQKDAhQb2xhclNTTDEZMBcGA1UEAwwQUG9sYXJTU0wgVGVz\r\n" \
"dCBDQTAeFw0xODA3MzExNzA3MzFaFw0yNzA5MDcxNzA3MzFaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwWTATBgcq\r\n" \
"hkjOPQIBBggqhkjOPQMBBwNCAATZ02ynxofvB2Ctqs273fSx4709TCopET5XDw4v\r\n" \
"BEdExNKRkfX7vyNWXWdyRWDi2BWWrK5LP8jZ51/qqgruoNeto00wSzAdBgNVHQ4E\r\n" \
"FgQUWAmoQppiCo35XT8WwagMkQ6TB3EwCQYDVR0TBAIwADAfBgNVHSMEGDAWgBS0\r\n" \
"WuSls97SUva51aaVD+s+vMf9/zANBgkqhkiG9w0BAQsFAAOCAQEAh6nGLNiWFUtC\r\n" \
"R3v3RWLNsru0X2EhZStd7rTIWGmJA9jhBe0QWnb1CrdrIgpRQujwLOfxP1lKmqIo\r\n" \
"7VGvpcaFOHNbrA73Gnut94H4MqFEhGGGdesnOEbYE2zGOij5CGwKx6Sm9qRF610o\r\n" \
"Oj2zVgu5rkgB4g25INxHc44r2ktLpNJ+Yk6Vc+U/MxYT1k8ETXAFM57H4Nxr21h8\r\n" \
"s+504I8xY/xwiXZfXydDNmRU44qereK8mrHLH0LA+rn0eMt/15fvINSiJXrKg8Fx\r\n" \
"q+oCjOixayqU2dwff4DFYu3dZ2c2EcYnwdHaI0aE9fLD40K3QcKjrewvmqOlihDW\r\n" \
"1qTugeVx7A==\r\n" \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_2048                               \
"-----BEGIN EC PRIVATE KEY-----\r\n"                                   \
"MHcCAQEEIC2qMl+6XPR+EooQlWWxgzTKRi9pgixuShP7F5AQ9sJ5oAoGCCqGSM49\r\n" \
"AwEHoUQDQgAE2dNsp8aH7wdgrarNu930seO9PUwqKRE+Vw8OLwRHRMTSkZH1+78j\r\n" \
"Vl1nckVg4tgVlqyuSz/I2edf6qoK7qDXrQ==\r\n"                             \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_2048                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n" \
"MIIEogIBAAKCAQEAzCwMKeoKRRO+/SkbChwRcbjd1uaQqgwrm0zYAPCj4rylsjZk\r\n" \
"LdCEtrveMqbO7MT+0e78UQT0pu2dV0mwTxwmihCxFXXv6RB8HIWovNfgJB3AjOq3\r\n" \
"vsTmWYF62pjwo7+KuMuW9PK6ddk8fk/CYbl+AJ0a/5lPgeqkMzw3e+wnpsaLstpB\r\n" \
"loxYz9R7XmloQTZxoys3D3RCCftUv0K24Uu16I67FwwjPv0dABxWQswGBnhHhU/Y\r\n" \
"mM412qVNIzNMu7Gir/PTm3hDZcjBnLmGfHWsP7jbsi0JwIssfozCdLQYmZQXc5az\r\n" \
"k1vQkBlufFSDKCKZBm6FRePWl3jrWTpfyJR8swIDAQABAoIBAEkWK3SFlw+LNf8h\r\n" \
"y9AepA/1gVQATSDSInoBVAFiIwhzR004MzxDPH69WZkAJWqUSjOUPTYzc/Cddolc\r\n" \
"k4R+Kz2ZJAruoObpQ8RiBDk1fcLv85F+JDBiA6Neuj+uJ9Y2Js5n8q3UhfLRxNni\r\n" \
"a07YO8a0domws8lp2UWN9L6jlr4YCQxCwUwH/Cc0Ui3NbGjEVbQ5mDE3M+RfZvGR\r\n" \
"hdYSmDSjs3tfGUQCodzGfDiUr2VVyIZlQxsief+8m/2JPw3HzRdlbjthG1aVr/XU\r\n" \
"t/L4Tw0IkCQeqKq+mgBd5f7kXdNkg8Dlz9wgN08yIZdAT8GWTF4JDte+NzuL5fkb\r\n" \
"DcOUoKECgYEA6Qdq1Y6G7YL1HzijbpHNBu/yzYip+rH5Vu6O6aU4geggkhIFT4mN\r\n" \
"oOObtGSt/glEG7txyIvECcPbEK0Zh0llxlEwubXB9u1iYBbHaiy6cw8HX3WUHYva\r\n" \
"r3l0AGHS08GVk6VD9whzK2+H3fqDLIuKhAcZYepRhDouHT2SyxOZ+o0CgYEA4Exp\r\n" \
"/hflNE/KsvEX95wcZLbOpY56m4wAS++Zv/hIpePBDEPleO3Ur5Rm3mABko1GhuGu\r\n" \
"HrZsXpwyH4rdLiukN93iKUvmrO/8gULZpdojhZrDljNFBWtjqIyKOBdkxlosRKF6\r\n" \
"lF1WsJHSSXm40Yyu+e539dLDyXZxgUZ2fQVEJD8CgYAJznwafKME/8vdAn8uOgiM\r\n" \
"0DBBogy1NiQuGl/9SSy1mtU0EHoUvM8vBCUbVFlWJYGuQRcqv2cCmjFv5Dj8zoPv\r\n" \
"8p7AUfvVrmvDa3H87+Dw0qMWy1XuYGJVnCDbm0JKEw1+ZygTD1H5c/odx1sZ1s1/\r\n" \
"fOT+j+PaUrB6Hos87JhASQKBgDdF3WDGVq87coICM5vLFpwjCG133PLz3ybXVpYe\r\n" \
"AxkONQZmvOe+BAl4kpj+I6UPt2+JsbTT04TFDP0E5Vh5XLB/tzniAGhhg2H/LU9X\r\n" \
"oCVObCBZZgrd2eMxLuZ/rU/L7NjEykZBchl09dMxccAB4SSqBVnIpILC81meGZjZ\r\n" \
"cV9VAoGAGhXQPEuhJJ++ViIf8VAA3xS/NFKlkmXIH2vc0luoDvzCMxOQXRYALE9k\r\n" \
"DdBFK598J6FfmqLBOMzZDtJvTspt7rbL4B+1HPn+/3fpZubVIHPcJ2+NYMA50n4W\r\n" \
"HV/QQP0EI0ttLHQ7BEOKoJFdaV1m/XsWGVTdArOdFQG+RcMMv18=\r\n" \
"-----END RSA PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_DH_PARAM_RSA_2048                                 \
"-----BEGIN DH PARAMETERS-----\r\n"                                    \
"MIIBCAKCAQEAsSBdhajoD+YbDe7jgDZTnjTZWgoIYrA8UIfxpFtiNzcPgwCrbTJI\r\n" \
"UGgY2TKFfnWJLu2GMjxgX4e/LLquG8kdzqRpsEt1CagyZ/drHX8H/YxOZfXZLj49\r\n" \
"YCPgS4dBbQCO7v54FqaJveiv8dCpwgIO+OWD3/NFcyWa2Yv1oqM+MsWnPvCW72oX\r\n" \
"brnJNKMgQdXIONieSGzq0fNuqPYw6Bg4f8ZqhstHgPCAv60FPr1IIuP7wDg7a/Mi\r\n" \
"IkjLWIy700RBq8bfEezuflB4prF5Hg/zsglg8j4MmPbZFJ4sFYkk8xS89zXPa9eU\r\n" \
"8mIRECpovUJkkBV6a2VhaML6TdCkOke6MwIBAg==\r\n"                         \
"-----END DH PARAMETERS-----\r\n"

/* ---- END RSA_2048 ---- */

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
"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\r\n" \
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
