import sys
def binar(x):
    return "{0:030b}".format(x)

n = int(sys.argv[1])

def F(n):
    if n == 0: return 0
    elif n == 1: return 1
    else: return F(n-1)+F(n-2)
import sys
def binar(x):
    return list("{0:063b}".format(x))

n = int(sys.argv[1])
abc = binar(n)
# print abc
print("".join(abc[abc.index("1"):]))

## Prime Sieve 
def F(n):
    if n==0:return 0
    elif n==1: return 1 
    else: return F(n-1)+F(n-2)

def fibonacci(n,a,b,c):
    count =0
    while(count<=n):
        c = a+b
        fib.append(c)
        b = a 
        a = c 
        count+=1
    return fib

odd = []
def odd_no(n):
    for i in range(n,0,-1):
        if i&1:
            odd.append(i)
    return odd


import sys
# args = map(float, sys.argv[1:])

def sys_ints():
    return map(float, sys.argv[1:])
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readChar():
    return raw_input()
def readChars():
    return raw_input().split()

def prime_sieve(limit):
    not_prime = set()
    primes = []
    limitn = limit+1

    for i in range(2, limitn):
        if i in not_prime:
            continue

        for f in range(i*2,limitn,i):
            not_prime.add(f)

        primes.append(i)
    return primes

import math
def prime_check(n):
    f = 0
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0:
            f =1 
            break
    if f==0:
        print "Prime"
    else:
        print "Not Prime"


def printdec(ans):
    return "{0:.6f}".format(ans)

n = int(sys.argv[1])
p = prime_sieve(n)
print p
if n in p:
    print printdec(math.sqrt(n))
else:
    print printdec(0)

prime_check(n)



a,b = sys_ints()
import random
from random import randint 
# print randint(a,b)

print random.uniform(a,b)


print sys.argv[1][::-1]

n,m = map(int, sys.argv[1:])
def hcf(n,m):
    # ans = 0
    # for i in range(2,min(n,m)+1):
    #     if n%i ==0 and m%i==0:
    #         ans = i
    # return ans
    while True:
        c = n%m
        if c==0:
            return m
        n,m = m,c

# print hcf(n,m)
def reverse_no(n):
    rev = 0
    while n>0:
        rem = n%10
        rev = rev*10+rem
        n/=10
    return rev

def sum_of_digits(n):
    sumi = 0
    while n>0:
        sumi+=n%10
        n/=10
    return sumi

d = float(sys.argv[1])
print reverse_no(n)
print sum_of_digits(n)

d/=2
print d
area = 22/float(7)*d*d
print printdec(area)

def remove_vowels(s):
    vowels = ['a','e','i','o','u']
    s1 =''.join([i for i in s if i.lower() not in vowels]) 
    return s1

print sys.argv[1:]
for i in sys.argv[1:]:
    print remove_vowels(i),

for string in sys.argv[1:]:
    print string.swapcase(),
        
def reverse_words(input):
    return ' '.join(input[-1::-1])

print reverse_words(sys.argv[1:])
print ' '.join(sys.argv[1:])[::-1]


# string = ' '.join(sys.argv[1:])
# print string.index('a')+1

s = sys.argv[1]
def incr_char(s):
    return ''.join([chr(ord(i)+1) for i in s])
    
print incr_char(s)

# CamelCase
print ' '.join(sys.argv[1:]).title()

def binar(x):
    return "{0:063b}".format(x)
n = int(sys.argv[1])
b = binar(n)
print b
print b.count("1")

round(ans, 2)

