#!/usr/bin/bc -l

scale = 14
a = 1/3
b = 2/3
#print "RSA Key Length? "
c = read()

t = l( l(2 ^ c) )
# if b < 1, then a^b == e (l(a) * b)
m = e( l(t) * b )
t = 64 / 9 * l(2 ^ c)
n = e( l(t) * a )
o = e( m * n )
p = l(o) / l(2)
print "Strength: ", p, "\n"
quit
