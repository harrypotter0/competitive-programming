import sys
def binar(x):
    return "{0:030b}".format(x)

n = int(sys.argv[1])

print(binar(n))
b = binar(n)

sumi = 0
b = b[::-1]
print b
for i in range(30):
    sumi+= pow(2,i)*int(b[i])
print sumi

