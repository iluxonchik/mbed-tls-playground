#!/usr/bin/python3
import sys
from subprocess import Popen

RSA_TO_ECC = {
    '1024' : 'secp192k1',
    '2048' : 'prime256v1',
    '4092' : 'secp384r1',
    '8192' : 'secp521r1',
    '15360' : 'secp521r1',
    '7680' : 'secp384r1',
}

def generate_DH_params(key_size):
    cwd = f'./rsa_{key_size}'
    p = Popen(f'openssl dhparam -dsaparam -out {key_size}_dhparam.pem {key_size}'.split(' '), cwd=cwd)
    p.wait()

def generate_EC_params(key_size):
    cwd = f'./rsa_{key_size}'
    curve_name = RSA_TO_ECC[key_size]

    p = Popen(f'openssl ecparam -name {curve_name} -genkey -out {curve_name}_private.pem'.split(' '), cwd=cwd)
    p.wait()

    p = Popen(f'openssl ec -in {curve_name}_private.pem -pubout -out {curve_name}_public.pem'.split(' '), cwd=cwd)
    p.wait()

def generate_ECDHE_RSA_certificate(key_size):

    cwd = f'./rsa_{key_size}'
    curve_name = RSA_TO_ECC[key_size]

    p = Popen(f'openssl req -new -key {curve_name}_private.pem -config ../conf.conf -out ecdh_rsa_out.csr'.split(' '), cwd=cwd)
    p.wait()

    p = Popen(f'openssl x509 -req -in ecdh_rsa_out.csr -CAkey ../ca_key_clear.pem -CA ../ca_cert.pem -force_pubkey ./{curve_name}_public.pem -out ecdh_rsa_cert.pem -CAcreateserial -days 1000'.split(' '), cwd=cwd)
    p.wait()

def generate_ECDHE_ECDSA_certificate(key_size):
    cwd = f'./rsa_{key_size}'
    curve_name = RSA_TO_ECC[key_size]

    try:
        p = Popen(f'openssl req -new -key {curve_name}_private.pem -config ../conf.conf -out ecdh_ecdsa_out.csr'.split(' '), cwd=cwd)
        p.wait()
    except:
        pass

    p = Popen(f'openssl x509 -req -in ecdh_ecdsa_out.csr -CAkey ../ec_cust/ca_priv_key.pem -CA ../ec_cust/ca_cert.pem -force_pubkey ./{curve_name}_public.pem -out ecdh_ecdsa_cert.pem -CAcreateserial -days 1000'.split(' '), cwd=cwd)
    p.wait()

def generate_RSA_certificate(key_size):
    p = Popen(f'rm -rf rsa_{key_size}'.split(' '))
    p.wait()
    p = Popen(f'mkdir rsa_{key_size}'.split(' '))
    p.wait()

    cwd = f'./rsa_{key_size}'

    p = Popen(f'openssl genrsa -out {key_size}_private.pem {key_size}'.split(' '), cwd=cwd)
    p.wait()
    p = Popen(f'openssl rsa -in {key_size}_private.pem -outform PEM -pubout -out {key_size}_public.pem'.split(' '), cwd=cwd)
    p.wait()
    p = Popen(f'openssl req -new -key {key_size}_private.pem -config ../conf.conf -out rsa_out.csr'.split(' '), cwd=cwd)
    p.wait()
    p = Popen(f'openssl x509 -req -in rsa_out.csr -CA ../ca_cert.pem -CAkey ../ca_key_clear.pem -CAcreateserial -out rsa_cert.pem -days 1000'.split(' '), cwd=cwd)
    p.wait()

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: genrsa.py <RSA_Key_Size>')
    key_size = sys.argv[1]

    generate_RSA_certificate(key_size)

    # Generate a public/private EC keypair
    generate_EC_params(key_size)

    generate_ECDHE_RSA_certificate(key_size)
    generate_ECDHE_ECDSA_certificate(key_size)

    generate_DH_params(key_size)

    print('[!!!] Do not forget to change the order of preferred curves in ecp.c')
    print('This is important to keep ECHD-* ciphersuites on the same security level')
