/*
 *  X.509 test certificates
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

#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include "mbedtls/certs.h"


/* [!!!] IMPORTANT: configuration NOTE !!!
 *
 * Go to certs.h file and configure the desired security level by uncommening the appropriate #define USE_RSA_XXXX.
 * Only one of the USE_RSA_XXXX can be defined! The security level of the remaining algorithms (e.g. ECC) will be
 * adjusted accordingly.
 */


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
#define PSK_256_BIT_RSA_15360 "71bc53a3beeaa416a4050653cec13d288e3eb692959cd0828499b702739e482c"

/* --- BEGIN RSA_2048 --- */

#define MBEDTLS_TEST_SRV_CRT_RSA_RSA_2048                              \
"-----BEGIN CERTIFICATE-----\r\n"                                      \
"MIIDPzCCAiegAwIBAgIJANBEZkZxdopmMA0GCSqGSIb3DQEBCwUAMDsxCzAJBgNV\r\n" \
"BAYTAk5MMREwDwYDVQQKDAhQb2xhclNTTDEZMBcGA1UEAwwQUG9sYXJTU0wgVGVz\r\n" \
"dCBDQTAeFw0xODAzMjcxNDEzMjFaFw0yNzA1MDQxNDEzMjFaMDQxCzAJBgNVBAYT\r\n" \
"Ak5MMREwDwYDVQQKEwhQb2xhclNTTDESMBAGA1UEAxMJbG9jYWxob3N0MIIBIjAN\r\n" \
"BgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAwU2j3efNHdEE10lyuJmsDnjkOjxK\r\n" \
"zzoTFtBa5M2jAIin7h5rlqdStJDvLXJ6PiSa/LY0rCT1d+AmZIycsCh9odrqjObJ\r\n" \
"HJa8/sEEUrM21KP64bF22JDBYbRmUjaiJlOqq3ReB30Zgtsq2B+g2Q0cLUlm91sl\r\n" \
"c0boC4pPaQy1AJDh2oIQZn2uVCuLZXmRoeJhw81ASQjuaAzxi4bSRr/QuKoRAx5/\r\n" \
"VqgaHkQYDw+Fi9qLRF7iGMZiL8dmjfpd2H3zJ4kpAcWQDj8n8TDISg7v1t7Hxydr\r\n" \
"xwU9esQCPJodPg/oNJhby3NLUpbYEaIsgIhpOVrTD7DeWS8Rx/fqEgEwlwIDAQAB\r\n" \
"o00wSzAdBgNVHQ4EFgQUpQXoZLjc32APUBJNYKhkr02LQ5MwCQYDVR0TBAIwADAf\r\n" \
"BgNVHSMEGDAWgBS0WuSls97SUva51aaVD+s+vMf9/zANBgkqhkiG9w0BAQsFAAOC\r\n" \
"AQEAcvY0HeIT7zmweE5/xk20kvFc0Qbc9dLzdxDlGLv7kDx/9brxjCRTa0/YejuT\r\n" \
"Pm8diFs1U6OvlzdROkbZpncW9c62mkg5zRrCo3T2E0SZx9GP8JNlo7MhiESjDsFO\r\n" \
"hcCGCKRnjOlyX4w25hA9JkwnkayeeTWnLwXS0BoFI2liWZNOLlxaSudffD4P1Hls\r\n" \
"vYOE0cU99bIkaZa9/aNygcjB08dUrD5AFvQO7S7gPCrpDrnuHEXi8EFlbGZfTAHy\r\n" \
"u+ozycErFLhYhZjtKUs2d1YsK4QKlI1PVjlucfrRXaEnLbi37cKqT68EceHh6ztd\r\n" \
"lPlhwRx+VicKsW8NHZ3k/wl3Yg==\r\n"                                     \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_2048                                \
"-----BEGIN CERTIFICATE-----\r\n"                                       \
"MIICHzCCAaWgAwIBAgIBCTAKBggqhkjOPQQDAjA+MQswCQYDVQQGEwJOTDERMA8G\r\n"  \
"A1UEChMIUG9sYXJTU0wxHDAaBgNVBAMTE1BvbGFyc3NsIFRlc3QgRUMgQ0EwHhcN\r\n"  \
"MTMwOTI0MTU1MjA0WhcNMjMwOTIyMTU1MjA0WjA0MQswCQYDVQQGEwJOTDERMA8G\r\n"  \
"A1UEChMIUG9sYXJTU0wxEjAQBgNVBAMTCWxvY2FsaG9zdDBZMBMGByqGSM49AgEG\r\n"  \
"CCqGSM49AwEHA0IABDfMVtl2CR5acj7HWS3/IG7ufPkGkXTQrRS192giWWKSTuUA\r\n"  \
"2CMR/+ov0jRdXRa9iojCa3cNVc2KKg76Aci07f+jgZ0wgZowCQYDVR0TBAIwADAd\r\n"  \
"BgNVHQ4EFgQUUGGlj9QH2deCAQzlZX+MY0anE74wbgYDVR0jBGcwZYAUnW0gJEkB\r\n"  \
"PyvLeLUZvH4kydv7NnyhQqRAMD4xCzAJBgNVBAYTAk5MMREwDwYDVQQKEwhQb2xh\r\n"  \
"clNTTDEcMBoGA1UEAxMTUG9sYXJzc2wgVGVzdCBFQyBDQYIJAMFD4n5iQ8zoMAoG\r\n"  \
"CCqGSM49BAMCA2gAMGUCMQCaLFzXptui5WQN8LlO3ddh1hMxx6tzgLvT03MTVK2S\r\n"  \
"C12r0Lz3ri/moSEpNZWqPjkCMCE2f53GXcYLqyfyJR078c/xNSUU5+Xxl7VZ414V\r\n"  \
"fGa5kHvHARBPc8YAIVIqDvHH1Q==\r\n"  \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_2048                         \
"-----BEGIN CERTIFICATE-----\r\n"                                      \
"MIICczCCAVugAwIBAgIJAL8pIYrgtDAkMA0GCSqGSIb3DQEBCwUAMDsxCzAJBgNV\r\n" \
"BAYTAk5MMREwDwYDVQQKDAhQb2xhclNTTDEZMBcGA1UEAwwQUG9sYXJTU0wgVGVz\r\n" \
"dCBDQTAeFw0xODA1MDYxNDUxMTlaFw0xODA2MDUxNDUxMTlaMDMxCzAJBgNVBAYT\r\n" \
"Ak5MMRAwDgYDVQQKDAdtYmVkVExTMRIwEAYDVQQDDAlsb2NhbGhvc3QwWTATBgcq\r\n" \
"hkjOPQIBBggqhkjOPQMBBwNCAAQ3zFbZdgkeWnI+x1kt/yBu7nz5BpF00K0Utfdo\r\n" \
"Illikk7lANgjEf/qL9I0XV0WvYqIwmt3DVXNiioO+gHItO3/o00wSzAdBgNVHQ4E\r\n" \
"FgQUUGGlj9QH2deCAQzlZX+MY0anE74wCQYDVR0TBAIwADAfBgNVHSMEGDAWgBS0\r\n" \
"WuSls97SUva51aaVD+s+vMf9/zANBgkqhkiG9w0BAQsFAAOCAQEAbROjJvA+6sts\r\n" \
"cTGV71oHOObWBYfJSTK3mFt+qN5LUDRUvRJXBG+0tVEAW9PGyS2jh4+SMCPk+Kgx\r\n" \
"xBbNLWBAJoW5KF22PjrCV3KkCcWX8hqzLKq1M5vLrOvYAqroGCS2rCxJJP05tGNm\r\n" \
"yK5Spc6X/M0Y79vCzVNSrKsBA2lOJ/TpPNpILkcJf6DUjNE43RxgcblW8lJgW3AL\r\n" \
"MVMb4aEgbEmZRh850DHvrs8WRBjdRKG4yDJMD7xHMgGwlJo+ULuqw6ICt0noqUdJ\r\n" \
"uaIZ8LnS9faLtbHskd8rtFoUFW/mzqierRpmCLslxswdARRP0LjjQhJzbxUmlOpE\r\n" \
"OLARMYNTSA==\r\n"                                                     \
"-----END CERTIFICATE-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_EC_RSA_2048                               \
"-----BEGIN EC PRIVATE KEY-----\r\n"                                   \
"MHcCAQEEIPEqEyB2AnCoPL/9U/YDHvdqXYbIogTywwyp6/UfDw6noAoGCCqGSM49\r\n" \
"AwEHoUQDQgAEN8xW2XYJHlpyPsdZLf8gbu58+QaRdNCtFLX3aCJZYpJO5QDYIxH/\r\n" \
"6i/SNF1dFr2KiMJrdw1VzYoqDvoByLTt/w==\r\n"                             \
"-----END EC PRIVATE KEY-----\r\n"

#define MBEDTLS_TEST_SRV_KEY_RSA_RSA_2048                               \
"-----BEGIN RSA PRIVATE KEY-----\r\n"                                   \
"MIIEpAIBAAKCAQEAwU2j3efNHdEE10lyuJmsDnjkOjxKzzoTFtBa5M2jAIin7h5r\r\n"  \
"lqdStJDvLXJ6PiSa/LY0rCT1d+AmZIycsCh9odrqjObJHJa8/sEEUrM21KP64bF2\r\n"  \
"2JDBYbRmUjaiJlOqq3ReB30Zgtsq2B+g2Q0cLUlm91slc0boC4pPaQy1AJDh2oIQ\r\n"  \
"Zn2uVCuLZXmRoeJhw81ASQjuaAzxi4bSRr/QuKoRAx5/VqgaHkQYDw+Fi9qLRF7i\r\n"  \
"GMZiL8dmjfpd2H3zJ4kpAcWQDj8n8TDISg7v1t7HxydrxwU9esQCPJodPg/oNJhb\r\n"  \
"y3NLUpbYEaIsgIhpOVrTD7DeWS8Rx/fqEgEwlwIDAQABAoIBAQCXR0S8EIHFGORZ\r\n"  \
"++AtOg6eENxD+xVs0f1IeGz57Tjo3QnXX7VBZNdj+p1ECvhCE/G7XnkgU5hLZX+G\r\n"  \
"Z0jkz/tqJOI0vRSdLBbipHnWouyBQ4e/A1yIJdlBtqXxJ1KE/ituHRbNc4j4kL8Z\r\n"  \
"/r6pvwnTI0PSx2Eqs048YdS92LT6qAv4flbNDxMn2uY7s4ycS4Q8w1JXnCeaAnYm\r\n"  \
"WYI5wxO+bvRELR2Mcz5DmVnL8jRyml6l6582bSv5oufReFIbyPZbQWlXgYnpu6He\r\n"  \
"GTc7E1zKYQGG/9+DQUl/1vQuCPqQwny0tQoX2w5tdYpdMdVm+zkLtbajzdTviJJa\r\n"  \
"TWzL6lt5AoGBAN86+SVeJDcmQJcv4Eq6UhtRr4QGMiQMz0Sod6ettYxYzMgxtw28\r\n"  \
"CIrgpozCc+UaZJLo7UxvC6an85r1b2nKPCLQFaggJ0H4Q0J/sZOhBIXaoBzWxveK\r\n"  \
"nupceKdVxGsFi8CDy86DBfiyFivfBj+47BbaQzPBj7C4rK7UlLjab2rDAoGBAN2u\r\n"  \
"AM2gchoFiu4v1HFL8D7lweEpi6ZnMJjnEu/dEgGQJFjwdpLnPbsj4c75odQ4Gz8g\r\n"  \
"sw9lao9VVzbusoRE/JGI4aTdO0pATXyG7eG1Qu+5Yc1YGXcCrliA2xM9xx+d7f+s\r\n"  \
"mPzN+WIEg5GJDYZDjAzHG5BNvi/FfM1C9dOtjv2dAoGAF0t5KmwbjWHBhcVqO4Ic\r\n"  \
"BVvN3BIlc1ue2YRXEDlxY5b0r8N4XceMgKmW18OHApZxfl8uPDauWZLXOgl4uepv\r\n"  \
"whZC3EuWrSyyICNhLY21Ah7hbIEBPF3L3ZsOwC+UErL+dXWLdB56Jgy3gZaBeW7b\r\n"  \
"vDrEnocJbqCm7IukhXHOBK8CgYEAwqdHB0hqyNSzIOGY7v9abzB6pUdA3BZiQvEs\r\n"  \
"3LjHVd4HPJ2x0N8CgrBIWOE0q8+0hSMmeE96WW/7jD3fPWwCR5zlXknxBQsfv0gP\r\n"  \
"3BC5PR0Qdypz+d+9zfMf625kyit4T/hzwhDveZUzHnk1Cf+IG7Q+TOEnLnWAWBED\r\n"  \
"ISOWmrUCgYAFEmRxgwAc/u+D6t0syCwAYh6POtscq9Y0i9GyWk89NzgC4NdwwbBH\r\n"  \
"4AgahOxIxXx2gxJnq3yfkJfIjwf0s2DyP0kY2y6Ua1OeomPeY9mrIS4tCuDQ6LrE\r\n"  \
"TB6l9VGoxJL4fyHnZb8L5gGvnB1bbD8cL6YPaDiOhcRseC9vBiEuVg==\r\n"  \
"-----END RSA PRIVATE KEY-----\r\n"

/* ---- END RSA_2048 ---- */

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


/* ---- END RSA_15360 ---- */

#ifdef USE_RSA_2048
// using RSA 2048 and equivalent key sizes

/* RSA */
const char mbedtls_test_srv_crt_rsa[] = MBEDTLS_TEST_SRV_CRT_RSA_RSA_2048;
const size_t mbedtls_test_srv_crt_rsa_len = sizeof( mbedtls_test_srv_crt_rsa );

const char mbedtls_test_srv_key_rsa[] = MBEDTLS_TEST_SRV_KEY_RSA_RSA_2048;
const size_t mbedtls_test_srv_key_rsa_len = sizeof( mbedtls_test_srv_key_rsa );


/* ECDH_ECDSA */
const char mbedtls_test_srv_crt_ec[] = MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_2048;
const size_t mbedtls_test_srv_crt_ec_len = sizeof( mbedtls_test_srv_crt_ec );

/*ECDH_RSA*/

/*
 * WARNING: this certificate will expire on July 5th, 2018
 *
 * To generate a new one, follow the steps in ~/Documents/tmp/certs/commands.txt
 */
const char mbedtls_test_srv_crt_ecdh_rsa[] = MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_2048;
const size_t mbedtls_test_srv_crt_ecdh_rsa_len = sizeof(mbedtls_test_srv_crt_ecdh_rsa);


const char mbedtls_test_srv_key_ec[] = MBEDTLS_TEST_SRV_KEY_EC_RSA_2048;
const size_t mbedtls_test_srv_key_ec_len = sizeof(mbedtls_test_srv_key_ec);

const char* psk_value = PSK_112_BIT_RSA_2048;
const size_t psk_value_len = sizeof(psk_value);

#endif // ifdef RSA_2048

#ifdef USE_RSA_15360

// using RSA 15360 and equivalent key sizes

/* RSA */
const char mbedtls_test_srv_crt_rsa[] = MBEDTLS_TEST_SRV_CRT_RSA_RSA_15360;
const size_t mbedtls_test_srv_crt_rsa_len = sizeof( mbedtls_test_srv_crt_rsa );

const char mbedtls_test_srv_key_rsa[] = MBEDTLS_TEST_SRV_KEY_RSA_RSA_15360;
const size_t mbedtls_test_srv_key_rsa_len = sizeof( mbedtls_test_srv_key_rsa );


/* ECDH_ECDSA */
const char mbedtls_test_srv_crt_ec[] = MBEDTLS_TEST_SRV_CRT_ECDH_ECDSA_RSA_15360;
const size_t mbedtls_test_srv_crt_ec_len = sizeof( mbedtls_test_srv_crt_ec );

/*ECDH_RSA*/

/*
 * WARNING: this certificate will expire on July 5th, 2018
 *
 * To generate a new one, follow the steps in ~/Documents/tmp/certs/commands.txt
 */
const char mbedtls_test_srv_crt_ecdh_rsa[] = MBEDTLS_TEST_SRV_CRT_ECDH_RSA_RSA_15360;
const size_t mbedtls_test_srv_crt_ecdh_rsa_len = sizeof(mbedtls_test_srv_crt_ecdh_rsa);


const char mbedtls_test_srv_key_ec[] = MBEDTLS_TEST_SRV_KEY_EC_RSA_15360;
const size_t mbedtls_test_srv_key_ec_len = sizeof(mbedtls_test_srv_key_ec);

const char* psk_value = PSK_256_BIT_RSA_15360;
const size_t psk_value_len = sizeof(psk_value);

#endif // USE_RSA_15360


const char* psk_identity = "The_Game";

#if defined(MBEDTLS_CERTS_C)

#if defined(MBEDTLS_ECDSA_C)
#define TEST_CA_CRT_EC                                                  \
"-----BEGIN CERTIFICATE-----\r\n"                                       \
"MIICUjCCAdegAwIBAgIJAMFD4n5iQ8zoMAoGCCqGSM49BAMCMD4xCzAJBgNVBAYT\r\n"  \
"Ak5MMREwDwYDVQQKEwhQb2xhclNTTDEcMBoGA1UEAxMTUG9sYXJzc2wgVGVzdCBF\r\n"  \
"QyBDQTAeFw0xMzA5MjQxNTQ5NDhaFw0yMzA5MjIxNTQ5NDhaMD4xCzAJBgNVBAYT\r\n"  \
"Ak5MMREwDwYDVQQKEwhQb2xhclNTTDEcMBoGA1UEAxMTUG9sYXJzc2wgVGVzdCBF\r\n"  \
"QyBDQTB2MBAGByqGSM49AgEGBSuBBAAiA2IABMPaKzRBN1gvh1b+/Im6KUNLTuBu\r\n"  \
"ww5XUzM5WNRStJGVOQsj318XJGJI/BqVKc4sLYfCiFKAr9ZqqyHduNMcbli4yuiy\r\n"  \
"aY7zQa0pw7RfdadHb9UZKVVpmlM7ILRmFmAzHqOBoDCBnTAdBgNVHQ4EFgQUnW0g\r\n"  \
"JEkBPyvLeLUZvH4kydv7NnwwbgYDVR0jBGcwZYAUnW0gJEkBPyvLeLUZvH4kydv7\r\n"  \
"NnyhQqRAMD4xCzAJBgNVBAYTAk5MMREwDwYDVQQKEwhQb2xhclNTTDEcMBoGA1UE\r\n"  \
"AxMTUG9sYXJzc2wgVGVzdCBFQyBDQYIJAMFD4n5iQ8zoMAwGA1UdEwQFMAMBAf8w\r\n"  \
"CgYIKoZIzj0EAwIDaQAwZgIxAMO0YnNWKJUAfXgSJtJxexn4ipg+kv4znuR50v56\r\n"  \
"t4d0PCu412mUC6Nnd7izvtE2MgIxAP1nnJQjZ8BWukszFQDG48wxCCyci9qpdSMv\r\n"  \
"uCjn8pwUOkABXK8Mss90fzCfCEOtIA==\r\n"                                  \
"-----END CERTIFICATE-----\r\n"
const char mbedtls_test_ca_crt_ec[] = TEST_CA_CRT_EC;
const size_t mbedtls_test_ca_crt_ec_len = sizeof( mbedtls_test_ca_crt_ec );

const char mbedtls_test_ca_key_ec[] =
"-----BEGIN EC PRIVATE KEY-----\r\n"
"Proc-Type: 4,ENCRYPTED\r\n"
"DEK-Info: DES-EDE3-CBC,307EAB469933D64E\r\n"
"\r\n"
"IxbrRmKcAzctJqPdTQLA4SWyBYYGYJVkYEna+F7Pa5t5Yg/gKADrFKcm6B72e7DG\r\n"
"ihExtZI648s0zdYw6qSJ74vrPSuWDe5qm93BqsfVH9svtCzWHW0pm1p0KTBCFfUq\r\n"
"UsuWTITwJImcnlAs1gaRZ3sAWm7cOUidL0fo2G0fYUFNcYoCSLffCFTEHBuPnagb\r\n"
"a77x/sY1Bvii8S9/XhDTb6pTMx06wzrm\r\n"
"-----END EC PRIVATE KEY-----\r\n";
const size_t mbedtls_test_ca_key_ec_len = sizeof( mbedtls_test_ca_key_ec );

const char mbedtls_test_ca_pwd_ec[] = "PolarSSLTest";
const size_t mbedtls_test_ca_pwd_ec_len = sizeof( mbedtls_test_ca_pwd_ec ) - 1;


const char mbedtls_test_cli_crt_ec[] =
"-----BEGIN CERTIFICATE-----\r\n"
"MIICLDCCAbKgAwIBAgIBDTAKBggqhkjOPQQDAjA+MQswCQYDVQQGEwJOTDERMA8G\r\n"
"A1UEChMIUG9sYXJTU0wxHDAaBgNVBAMTE1BvbGFyc3NsIFRlc3QgRUMgQ0EwHhcN\r\n"
"MTMwOTI0MTU1MjA0WhcNMjMwOTIyMTU1MjA0WjBBMQswCQYDVQQGEwJOTDERMA8G\r\n"
"A1UEChMIUG9sYXJTU0wxHzAdBgNVBAMTFlBvbGFyU1NMIFRlc3QgQ2xpZW50IDIw\r\n"
"WTATBgcqhkjOPQIBBggqhkjOPQMBBwNCAARX5a6xc9/TrLuTuIH/Eq7u5lOszlVT\r\n"
"9jQOzC7jYyUL35ji81xgNpbA1RgUcOV/n9VLRRjlsGzVXPiWj4dwo+THo4GdMIGa\r\n"
"MAkGA1UdEwQCMAAwHQYDVR0OBBYEFHoAX4Zk/OBd5REQO7LmO8QmP8/iMG4GA1Ud\r\n"
"IwRnMGWAFJ1tICRJAT8ry3i1Gbx+JMnb+zZ8oUKkQDA+MQswCQYDVQQGEwJOTDER\r\n"
"MA8GA1UEChMIUG9sYXJTU0wxHDAaBgNVBAMTE1BvbGFyc3NsIFRlc3QgRUMgQ0GC\r\n"
"CQDBQ+J+YkPM6DAKBggqhkjOPQQDAgNoADBlAjBKZQ17IIOimbmoD/yN7o89u3BM\r\n"
"lgOsjnhw3fIOoLIWy2WOGsk/LGF++DzvrRzuNiACMQCd8iem1XS4JK7haj8xocpU\r\n"
"LwjQje5PDGHfd3h9tP38Qknu5bJqws0md2KOKHyeV0U=\r\n"
"-----END CERTIFICATE-----\r\n";
const size_t mbedtls_test_cli_crt_ec_len = sizeof( mbedtls_test_cli_crt_ec );

const char mbedtls_test_cli_key_ec[] =
"-----BEGIN EC PRIVATE KEY-----\r\n"
"MHcCAQEEIPb3hmTxZ3/mZI3vyk7p3U3wBf+WIop6hDhkFzJhmLcqoAoGCCqGSM49\r\n"
"AwEHoUQDQgAEV+WusXPf06y7k7iB/xKu7uZTrM5VU/Y0Dswu42MlC9+Y4vNcYDaW\r\n"
"wNUYFHDlf5/VS0UY5bBs1Vz4lo+HcKPkxw==\r\n"
"-----END EC PRIVATE KEY-----\r\n";
const size_t mbedtls_test_cli_key_ec_len = sizeof( mbedtls_test_cli_key_ec );
#endif /* MBEDTLS_ECDSA_C */

#if defined(MBEDTLS_RSA_C)

#if defined(MBEDTLS_SHA256_C)
#define TEST_CA_CRT_RSA_SHA256                                          \
"-----BEGIN CERTIFICATE-----\r\n"                                       \
"MIIDhzCCAm+gAwIBAgIBADANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJOTDER\r\n"  \
"MA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0EwHhcN\r\n"  \
"MTcwNTA0MTY1NzAxWhcNMjcwNTA1MTY1NzAxWjA7MQswCQYDVQQGEwJOTDERMA8G\r\n"  \
"A1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0EwggEiMA0G\r\n"  \
"CSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDA3zf8F7vglp0/ht6WMn1EpRagzSHx\r\n"  \
"mdTs6st8GFgIlKXsm8WL3xoemTiZhx57wI053zhdcHgH057Zk+i5clHFzqMwUqny\r\n"  \
"50BwFMtEonILwuVA+T7lpg6z+exKY8C4KQB0nFc7qKUEkHHxvYPZP9al4jwqj+8n\r\n"  \
"YMPGn8u67GB9t+aEMr5P+1gmIgNb1LTV+/Xjli5wwOQuvfwu7uJBVcA0Ln0kcmnL\r\n"  \
"R7EUQIN9Z/SG9jGr8XmksrUuEvmEF/Bibyc+E1ixVA0hmnM3oTDPb5Lc9un8rNsu\r\n"  \
"KNF+AksjoBXyOGVkCeoMbo4bF6BxyLObyavpw/LPh5aPgAIynplYb6LVAgMBAAGj\r\n"  \
"gZUwgZIwHQYDVR0OBBYEFLRa5KWz3tJS9rnVppUP6z68x/3/MGMGA1UdIwRcMFqA\r\n"  \
"FLRa5KWz3tJS9rnVppUP6z68x/3/oT+kPTA7MQswCQYDVQQGEwJOTDERMA8GA1UE\r\n"  \
"CgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0GCAQAwDAYDVR0T\r\n"  \
"BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAHK/HHrTZMnnVMpde1io+voAtql7j\r\n"  \
"4sRhLrjD7o3THtwRbDa2diCvpq0Sq23Ng2LMYoXsOxoL/RQK3iN7UKxV3MKPEr0w\r\n"  \
"XQS+kKQqiT2bsfrjnWMVHZtUOMpm6FNqcdGm/Rss3vKda2lcKl8kUnq/ylc1+QbB\r\n"  \
"G6A6tUvQcr2ZyWfVg+mM5XkhTrOOXus2OLikb4WwEtJTJRNE0f+yPODSUz0/vT57\r\n"  \
"ApH0CnB80bYJshYHPHHymOtleAB8KSYtqm75g/YNobjnjB6cm4HkW3OZRVIl6fYY\r\n"  \
"n20NRVA1Vjs6GAROr4NqW4k/+LofY9y0LLDE+p0oIEKXIsIvhPr39swxSA==\r\n"      \
"-----END CERTIFICATE-----\r\n"

const char   mbedtls_test_ca_crt_rsa[]   = TEST_CA_CRT_RSA_SHA256;
const size_t mbedtls_test_ca_crt_rsa_len = sizeof( mbedtls_test_ca_crt_rsa );
#define TEST_CA_CRT_RSA_SOME

static const char mbedtls_test_ca_crt_rsa_sha256[] = TEST_CA_CRT_RSA_SHA256;

#endif

#if !defined(TEST_CA_CRT_RSA_SOME) || defined(MBEDTLS_SHA1_C)
#define TEST_CA_CRT_RSA_SHA1                                            \
"-----BEGIN CERTIFICATE-----\r\n"                                       \
"MIIDhzCCAm+gAwIBAgIBADANBgkqhkiG9w0BAQUFADA7MQswCQYDVQQGEwJOTDER\r\n"  \
"MA8GA1UEChMIUG9sYXJTU0wxGTAXBgNVBAMTEFBvbGFyU1NMIFRlc3QgQ0EwHhcN\r\n"  \
"MTEwMjEyMTQ0NDAwWhcNMjEwMjEyMTQ0NDAwWjA7MQswCQYDVQQGEwJOTDERMA8G\r\n"  \
"A1UEChMIUG9sYXJTU0wxGTAXBgNVBAMTEFBvbGFyU1NMIFRlc3QgQ0EwggEiMA0G\r\n"  \
"CSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDA3zf8F7vglp0/ht6WMn1EpRagzSHx\r\n"  \
"mdTs6st8GFgIlKXsm8WL3xoemTiZhx57wI053zhdcHgH057Zk+i5clHFzqMwUqny\r\n"  \
"50BwFMtEonILwuVA+T7lpg6z+exKY8C4KQB0nFc7qKUEkHHxvYPZP9al4jwqj+8n\r\n"  \
"YMPGn8u67GB9t+aEMr5P+1gmIgNb1LTV+/Xjli5wwOQuvfwu7uJBVcA0Ln0kcmnL\r\n"  \
"R7EUQIN9Z/SG9jGr8XmksrUuEvmEF/Bibyc+E1ixVA0hmnM3oTDPb5Lc9un8rNsu\r\n"  \
"KNF+AksjoBXyOGVkCeoMbo4bF6BxyLObyavpw/LPh5aPgAIynplYb6LVAgMBAAGj\r\n"  \
"gZUwgZIwDAYDVR0TBAUwAwEB/zAdBgNVHQ4EFgQUtFrkpbPe0lL2udWmlQ/rPrzH\r\n"  \
"/f8wYwYDVR0jBFwwWoAUtFrkpbPe0lL2udWmlQ/rPrzH/f+hP6Q9MDsxCzAJBgNV\r\n"  \
"BAYTAk5MMREwDwYDVQQKEwhQb2xhclNTTDEZMBcGA1UEAxMQUG9sYXJTU0wgVGVz\r\n"  \
"dCBDQYIBADANBgkqhkiG9w0BAQUFAAOCAQEAuP1U2ABUkIslsCfdlc2i94QHHYeJ\r\n"  \
"SsR4EdgHtdciUI5I62J6Mom+Y0dT/7a+8S6MVMCZP6C5NyNyXw1GWY/YR82XTJ8H\r\n"  \
"DBJiCTok5DbZ6SzaONBzdWHXwWwmi5vg1dxn7YxrM9d0IjxM27WNKs4sDQhZBQkF\r\n"  \
"pjmfs2cb4oPl4Y9T9meTx/lvdkRYEug61Jfn6cA+qHpyPYdTH+UshITnmp5/Ztkf\r\n"  \
"m/UTSLBNFNHesiTZeH31NcxYGdHSme9Nc/gfidRa0FLOCfWxRlFqAI47zG9jAQCZ\r\n"  \
"7Z2mCGDNMhjQc+BYcdnl0lPXjdDK6V0qCg1dVewhUBcW5gZKzV7e9+DpVA==\r\n"      \
"-----END CERTIFICATE-----\r\n"

#if !defined (TEST_CA_CRT_RSA_SOME)
const char   mbedtls_test_ca_crt_rsa[]   = TEST_CA_CRT_RSA_SHA1;
const size_t mbedtls_test_ca_crt_rsa_len = sizeof( mbedtls_test_ca_crt_rsa );
#endif

static const char mbedtls_test_ca_crt_rsa_sha1[] = TEST_CA_CRT_RSA_SHA1;

#endif

const char mbedtls_test_ca_key_rsa[] =
"-----BEGIN RSA PRIVATE KEY-----\r\n"
"Proc-Type: 4,ENCRYPTED\r\n"
"DEK-Info: DES-EDE3-CBC,A8A95B05D5B7206B\r\n"
"\r\n"
"9Qd9GeArejl1GDVh2lLV1bHt0cPtfbh5h/5zVpAVaFpqtSPMrElp50Rntn9et+JA\r\n"
"7VOyboR+Iy2t/HU4WvA687k3Bppe9GwKHjHhtl//8xFKwZr3Xb5yO5JUP8AUctQq\r\n"
"Nb8CLlZyuUC+52REAAthdWgsX+7dJO4yabzUcQ22Tp9JSD0hiL43BlkWYUNK3dAo\r\n"
"PZlmiptjnzVTjg1MxsBSydZinWOLBV8/JQgxSPo2yD4uEfig28qbvQ2wNIn0pnAb\r\n"
"GxnSAOazkongEGfvcjIIs+LZN9gXFhxcOh6kc4Q/c99B7QWETwLLkYgZ+z1a9VY9\r\n"
"gEU7CwCxYCD+h9hY6FPmsK0/lC4O7aeRKpYq00rPPxs6i7phiexg6ax6yTMmArQq\r\n"
"QmK3TAsJm8V/J5AWpLEV6jAFgRGymGGHnof0DXzVWZidrcZJWTNuGEX90nB3ee2w\r\n"
"PXJEFWKoD3K3aFcSLdHYr3mLGxP7H9ThQai9VsycxZKS5kwvBKQ//YMrmFfwPk8x\r\n"
"vTeY4KZMaUrveEel5tWZC94RSMKgxR6cyE1nBXyTQnDOGbfpNNgBKxyKbINWoOJU\r\n"
"WJZAwlsQn+QzCDwpri7+sV1mS3gBE6UY7aQmnmiiaC2V3Hbphxct/en5QsfDOt1X\r\n"
"JczSfpRWLlbPznZg8OQh/VgCMA58N5DjOzTIK7sJJ5r+94ZBTCpgAMbF588f0NTR\r\n"
"KCe4yrxGJR7X02M4nvD4IwOlpsQ8xQxZtOSgXv4LkxvdU9XJJKWZ/XNKJeWztxSe\r\n"
"Z1vdTc2YfsDBA2SEv33vxHx2g1vqtw8SjDRT2RaQSS0QuSaMJimdOX6mTOCBKk1J\r\n"
"9Q5mXTrER+/LnK0jEmXsBXWA5bqqVZIyahXSx4VYZ7l7w/PHiUDtDgyRhMMKi4n2\r\n"
"iQvQcWSQTjrpnlJbca1/DkpRt3YwrvJwdqb8asZU2VrNETh5x0QVefDRLFiVpif/\r\n"
"tUaeAe/P1F8OkS7OIZDs1SUbv/sD2vMbhNkUoCms3/PvNtdnvgL4F0zhaDpKCmlT\r\n"
"P8vx49E7v5CyRNmED9zZg4o3wmMqrQO93PtTug3Eu9oVx1zPQM1NVMyBa2+f29DL\r\n"
"1nuTCeXdo9+ni45xx+jAI4DCwrRdhJ9uzZyC6962H37H6D+5naNvClFR1s6li1Gb\r\n"
"nqPoiy/OBsEx9CaDGcqQBp5Wme/3XW+6z1ISOx+igwNTVCT14mHdBMbya0eIKft5\r\n"
"X+GnwtgEMyCYyyWuUct8g4RzErcY9+yW9Om5Hzpx4zOuW4NPZgPDTgK+t2RSL/Yq\r\n"
"rE1njrgeGYcVeG3f+OftH4s6fPbq7t1A5ZgUscbLMBqr9tK+OqygR4EgKBPsH6Cz\r\n"
"L6zlv/2RV0qAHvVuDJcIDIgwY5rJtINEm32rhOeFNJwZS5MNIC1czXZx5//ugX7l\r\n"
"I4sy5nbVhwSjtAk8Xg5dZbdTZ6mIrb7xqH+fdakZor1khG7bC2uIwibD3cSl2XkR\r\n"
"wN48lslbHnqqagr6Xm1nNOSVl8C/6kbJEsMpLhAezfRtGwvOucoaE+WbeUNolGde\r\n"
"P/eQiddSf0brnpiLJRh7qZrl9XuqYdpUqnoEdMAfotDOID8OtV7gt8a48ad8VPW2\r\n"
"-----END RSA PRIVATE KEY-----\r\n";
const size_t mbedtls_test_ca_key_rsa_len = sizeof( mbedtls_test_ca_key_rsa );

const char mbedtls_test_ca_pwd_rsa[] = "PolarSSLTest";
const size_t mbedtls_test_ca_pwd_rsa_len = sizeof( mbedtls_test_ca_pwd_rsa ) - 1;

const char mbedtls_test_cli_crt_rsa[] =
"-----BEGIN CERTIFICATE-----\r\n"
"MIIDhTCCAm2gAwIBAgIBBDANBgkqhkiG9w0BAQsFADA7MQswCQYDVQQGEwJOTDER\r\n"
"MA8GA1UECgwIUG9sYXJTU0wxGTAXBgNVBAMMEFBvbGFyU1NMIFRlc3QgQ0EwHhcN\r\n"
"MTcwNTA1MTMwNzU5WhcNMjcwNTA2MTMwNzU5WjA8MQswCQYDVQQGEwJOTDERMA8G\r\n"
"A1UECgwIUG9sYXJTU0wxGjAYBgNVBAMMEVBvbGFyU1NMIENsaWVudCAyMIIBIjAN\r\n"
"BgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAyHTEzLn5tXnpRdkUYLB9u5Pyax6f\r\n"
"M60Nj4o8VmXl3ETZzGaFB9X4J7BKNdBjngpuG7fa8H6r7gwQk4ZJGDTzqCrSV/Uu\r\n"
"1C93KYRhTYJQj6eVSHD1bk2y1RPD0hrt5kPqQhTrdOrA7R/UV06p86jt0uDBMHEw\r\n"
"MjDV0/YI0FZPRo7yX/k9Z5GIMC5Cst99++UMd//sMcB4j7/Cf8qtbCHWjdmLao5v\r\n"
"4Jv4EFbMs44TFeY0BGbH7vk2DmqV9gmaBmf0ZXH4yqSxJeD+PIs1BGe64E92hfx/\r\n"
"/DZrtenNLQNiTrM9AM+vdqBpVoNq0qjU51Bx5rU2BXcFbXvI5MT9TNUhXwIDAQAB\r\n"
"o4GSMIGPMB0GA1UdDgQWBBRxoQBzckAvVHZeM/xSj7zx3WtGITBjBgNVHSMEXDBa\r\n"
"gBS0WuSls97SUva51aaVD+s+vMf9/6E/pD0wOzELMAkGA1UEBhMCTkwxETAPBgNV\r\n"
"BAoMCFBvbGFyU1NMMRkwFwYDVQQDDBBQb2xhclNTTCBUZXN0IENBggEAMAkGA1Ud\r\n"
"EwQCMAAwDQYJKoZIhvcNAQELBQADggEBAC7yO786NvcHpK8UovKIG9cB32oSQQom\r\n"
"LoR0eHDRzdqEkoq7yGZufHFiRAAzbMqJfogRtxlrWAeB4y/jGaMBV25IbFOIcH2W\r\n"
"iCEaMMbG+VQLKNvuC63kmw/Zewc9ThM6Pa1Hcy0axT0faf1B/U01j0FIcw/6mTfK\r\n"
"D8w48OIwc1yr0JtutCVjig5DC0yznGMt32RyseOLcUe+lfq005v2PAiCozr5X8rE\r\n"
"ofGZpiM2NqRPePgYy+Vc75Zk28xkRQq1ncprgQb3S4vTsZdScpM9hLf+eMlrgqlj\r\n"
"c5PLSkXBeLE5+fedkyfTaLxxQlgCpuoOhKBm04/R1pWNzUHyqagjO9Q=\r\n"
"-----END CERTIFICATE-----\r\n";
const size_t mbedtls_test_cli_crt_rsa_len = sizeof( mbedtls_test_cli_crt_rsa );

const char mbedtls_test_cli_key_rsa[] =
"-----BEGIN RSA PRIVATE KEY-----\r\n"
"MIIEpAIBAAKCAQEAyHTEzLn5tXnpRdkUYLB9u5Pyax6fM60Nj4o8VmXl3ETZzGaF\r\n"
"B9X4J7BKNdBjngpuG7fa8H6r7gwQk4ZJGDTzqCrSV/Uu1C93KYRhTYJQj6eVSHD1\r\n"
"bk2y1RPD0hrt5kPqQhTrdOrA7R/UV06p86jt0uDBMHEwMjDV0/YI0FZPRo7yX/k9\r\n"
"Z5GIMC5Cst99++UMd//sMcB4j7/Cf8qtbCHWjdmLao5v4Jv4EFbMs44TFeY0BGbH\r\n"
"7vk2DmqV9gmaBmf0ZXH4yqSxJeD+PIs1BGe64E92hfx//DZrtenNLQNiTrM9AM+v\r\n"
"dqBpVoNq0qjU51Bx5rU2BXcFbXvI5MT9TNUhXwIDAQABAoIBAGdNtfYDiap6bzst\r\n"
"yhCiI8m9TtrhZw4MisaEaN/ll3XSjaOG2dvV6xMZCMV+5TeXDHOAZnY18Yi18vzz\r\n"
"4Ut2TnNFzizCECYNaA2fST3WgInnxUkV3YXAyP6CNxJaCmv2aA0yFr2kFVSeaKGt\r\n"
"ymvljNp2NVkvm7Th8fBQBO7I7AXhz43k0mR7XmPgewe8ApZOG3hstkOaMvbWAvWA\r\n"
"zCZupdDjZYjOJqlA4eEA4H8/w7F83r5CugeBE8LgEREjLPiyejrU5H1fubEY+h0d\r\n"
"l5HZBJ68ybTXfQ5U9o/QKA3dd0toBEhhdRUDGzWtjvwkEQfqF1reGWj/tod/gCpf\r\n"
"DFi6X0ECgYEA4wOv/pjSC3ty6TuOvKX2rOUiBrLXXv2JSxZnMoMiWI5ipLQt+RYT\r\n"
"VPafL/m7Dn6MbwjayOkcZhBwk5CNz5A6Q4lJ64Mq/lqHznRCQQ2Mc1G8eyDF/fYL\r\n"
"Ze2pLvwP9VD5jTc2miDfw+MnvJhywRRLcemDFP8k4hQVtm8PMp3ZmNECgYEA4gz7\r\n"
"wzObR4gn8ibe617uQPZjWzUj9dUHYd+in1gwBCIrtNnaRn9I9U/Q6tegRYpii4ys\r\n"
"c176NmU+umy6XmuSKV5qD9bSpZWG2nLFnslrN15Lm3fhZxoeMNhBaEDTnLT26yoi\r\n"
"33gp0mSSWy94ZEqipms+ULF6sY1ZtFW6tpGFoy8CgYAQHhnnvJflIs2ky4q10B60\r\n"
"ZcxFp3rtDpkp0JxhFLhiizFrujMtZSjYNm5U7KkgPVHhLELEUvCmOnKTt4ap/vZ0\r\n"
"BxJNe1GZH3pW6SAvGDQpl9sG7uu/vTFP+lCxukmzxB0DrrDcvorEkKMom7ZCCRvW\r\n"
"KZsZ6YeH2Z81BauRj218kQKBgQCUV/DgKP2985xDTT79N08jUo3hTP5MVYCCuj/+\r\n"
"UeEw1TvZcx3LJby7P6Xad6a1/BqveaGyFKIfEFIaBUBItk801sDDpDaYc4gL00Xc\r\n"
"7lFuBHOZkxJYlss5QrGpuOEl9ZwUt5IrFLBdYaKqNHzNVC1pCPfb/JyH6Dr2HUxq\r\n"
"gxUwAQKBgQCcU6G2L8AG9d9c0UpOyL1tMvFe5Ttw0KjlQVdsh1MP6yigYo9DYuwu\r\n"
"bHFVW2r0dBTqegP2/KTOxKzaHfC1qf0RGDsUoJCNJrd1cwoCLG8P2EF4w3OBrKqv\r\n"
"8u4ytY0F+Vlanj5lm3TaoHSVF1+NWPyOTiwevIECGKwSxvlki4fDAA==\r\n"
"-----END RSA PRIVATE KEY-----\r\n";
const size_t mbedtls_test_cli_key_rsa_len = sizeof( mbedtls_test_cli_key_rsa );
#endif /* MBEDTLS_RSA_C */

#if defined(MBEDTLS_PEM_PARSE_C)
/* Concatenation of all available CA certificates */
const char mbedtls_test_cas_pem[] =
#ifdef TEST_CA_CRT_RSA_SHA1
    TEST_CA_CRT_RSA_SHA1
#endif
#ifdef TEST_CA_CRT_RSA_SHA256
    TEST_CA_CRT_RSA_SHA256
#endif
#ifdef TEST_CA_CRT_EC
    TEST_CA_CRT_EC
#endif
    "";
const size_t mbedtls_test_cas_pem_len = sizeof( mbedtls_test_cas_pem );
#endif

/* List of all available CA certificates */
const char * mbedtls_test_cas[] = {
#if defined(TEST_CA_CRT_RSA_SHA1)
    mbedtls_test_ca_crt_rsa_sha1,
#endif
#if defined(TEST_CA_CRT_RSA_SHA256)
    mbedtls_test_ca_crt_rsa_sha256,
#endif
#if defined(MBEDTLS_ECDSA_C)
    mbedtls_test_ca_crt_ec,
#endif
    NULL
};
const size_t mbedtls_test_cas_len[] = {
#if defined(TEST_CA_CRT_RSA_SHA1)
    sizeof( mbedtls_test_ca_crt_rsa_sha1 ),
#endif
#if defined(TEST_CA_CRT_RSA_SHA256)
    sizeof( mbedtls_test_ca_crt_rsa_sha256 ),
#endif
#if defined(MBEDTLS_ECDSA_C)
    sizeof( mbedtls_test_ca_crt_ec ),
#endif
    0
};

#if defined(MBEDTLS_RSA_C)
const char *mbedtls_test_ca_crt  = mbedtls_test_ca_crt_rsa; /* SHA1 or SHA256 */
const char *mbedtls_test_ca_key  = mbedtls_test_ca_key_rsa;
const char *mbedtls_test_ca_pwd  = mbedtls_test_ca_pwd_rsa;
const char *mbedtls_test_srv_crt = mbedtls_test_srv_crt_rsa;
const char *mbedtls_test_srv_key = mbedtls_test_srv_key_rsa;
const char *mbedtls_test_cli_crt = mbedtls_test_cli_crt_rsa;
const char *mbedtls_test_cli_key = mbedtls_test_cli_key_rsa;
const size_t mbedtls_test_ca_crt_len  = sizeof( mbedtls_test_ca_crt_rsa );
const size_t mbedtls_test_ca_key_len  = sizeof( mbedtls_test_ca_key_rsa );
const size_t mbedtls_test_ca_pwd_len  = sizeof( mbedtls_test_ca_pwd_rsa ) - 1;
const size_t mbedtls_test_srv_crt_len = sizeof( mbedtls_test_srv_crt_rsa );
const size_t mbedtls_test_srv_key_len = sizeof( mbedtls_test_srv_key_rsa );
const size_t mbedtls_test_cli_crt_len = sizeof( mbedtls_test_cli_crt_rsa );
const size_t mbedtls_test_cli_key_len = sizeof( mbedtls_test_cli_key_rsa );
#else /* ! MBEDTLS_RSA_C, so MBEDTLS_ECDSA_C */
const char *mbedtls_test_ca_crt  = mbedtls_test_ca_crt_ec;
const char *mbedtls_test_ca_key  = mbedtls_test_ca_key_ec;
const char *mbedtls_test_ca_pwd  = mbedtls_test_ca_pwd_ec;
const char *mbedtls_test_srv_crt = mbedtls_test_srv_crt_ec;
const char *mbedtls_test_srv_key = mbedtls_test_srv_key_ec;
const char *mbedtls_test_cli_crt = mbedtls_test_cli_crt_ec;
const char *mbedtls_test_cli_key = mbedtls_test_cli_key_ec;
const size_t mbedtls_test_ca_crt_len  = sizeof( mbedtls_test_ca_crt_ec );
const size_t mbedtls_test_ca_key_len  = sizeof( mbedtls_test_ca_key_ec );
const size_t mbedtls_test_ca_pwd_len  = sizeof( mbedtls_test_ca_pwd_ec ) - 1;
const size_t mbedtls_test_srv_crt_len = sizeof( mbedtls_test_srv_crt_ec );
const size_t mbedtls_test_srv_key_len = sizeof( mbedtls_test_srv_key_ec );
const size_t mbedtls_test_cli_crt_len = sizeof( mbedtls_test_cli_crt_ec );
const size_t mbedtls_test_cli_key_len = sizeof( mbedtls_test_cli_key_ec );
#endif /* MBEDTLS_RSA_C */

#endif /* MBEDTLS_CERTS_C */
