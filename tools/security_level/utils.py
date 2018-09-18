import math
import sys

def rsa_to_sym(key_size):
    scale = 14
    a = 1/3
    b = 2/3 
    t = math.log(math.log(2**key_size))
    m = math.log(t)**b
    t = 64/9 * math.log(2**key_size)
    n = math.log(t)**a
    o = m**n
    p = math.log(o)/math.log(2)
    return p

print(rsa_to_sym(int(sys.argv[1])))
