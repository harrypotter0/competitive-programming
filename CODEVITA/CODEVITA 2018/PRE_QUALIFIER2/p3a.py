# /*
#  *
#  ********************************************************************************************
#  * AUTHOR : AKASH KANDPAL                                                                   *
#  * Language : Python2                                                                       *
#  * Motto : The master has failed more times than the beginner has even tried.               *
#  * IDE used: Atom                                                                           *
#  * My Domain : http://harrypotter.tech/                                                     *
#  ********************************************************************************************
#  *
#  */
from collections import Counter
from math import ceil
from fractions import gcd
import math
import itertools
from itertools import permutations
from itertools import combinations
import calendar
from itertools import product
from datetime import date
from string import ascii_uppercase
import sys
from bisect import bisect_left
from collections import defaultdict

sys.setrecursionlimit(10000)

def readInts():
    return list(map(int, raw_input().strip().split(',')))
def readInt():
    return int(raw_input())
def primes_sieve(limit):
    limitn = limit+1
    not_prime = set()
    primes = []

    for i in range(2, limitn):
        if i in not_prime:
            continue

        for f in range(i*2, limitn, i):
            not_prime.add(f)

        primes.append(i)

    return primes
# def SieveOfEratosthenes(n, ind):
#     count = 0     
#     prime = [True for i in range(n+1)]
#     p = 2
#     while (p * p <= n):
#         if (prime[p] == True):
#             for i in range(p * 2, n+1, p):
#                 prime[i] = False
#         p += 1     
#     for p in range(2, n):
#         if prime[p]:
#             count+=1
#         if count == ind:
#             return p
def SieveOfEratosthenes(n):
    pr = []     
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
         
        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
             
            # Update all multiples of p
            for i in range(p * 2, n+1, p):
                prime[i] = False
        p += 1
     
    # Print all prime numbers
    for p in range(2, n):
        if prime[p]:
            pr.append(p)
            # print p,
    return pr
 
# m = 329885391853
# lim =  prelongfact(m)

mod = 10 ** 9 + 7

def valAt(x,y):
	if x>y:
		if x+y > 0:
			n  = 4*x*x - 3*x + y
		else :
			n  = 4*y*y - 3*y + x
	else:
		if x+y > 0:
			n  = 4*y*y -  x - y
		else :
			n  = 4*x*x -  y - x
	return n

# #!/usr/bin/python

# import re, sys


# def isPrime(n):
#     # see http://www.noulakaz.net/weblog/2007/03/18/a-regular-expression-to-check-for-prime-numbers/
#     return re.match(r'^1?$|^(11+?)\1+$', '1' * n) == None



prime = SieveOfEratosthenes(1000000)
n =readInt()
for i in range(n):
    a,b = readInts()
    if a== b and a== 0:
        print "2"
    else:
        # print valAt(a,b)
        # print valAt(a,b)+1
        print prime[valAt(a,b)]
        # print SieveOfEratosthenes(500000,valAt(a,b)+1)



 


'''
Example 1

Input

3
1,0
0,1
-130,-130

Output

3
7

Explanation

N=2. There are 2 sets of coordinates in this test case. The coordinates are (1,0) and (0,1).. The corresponding primes in the spiral are 3 and 7. The output hence has these.

Example 2

Input

3
1,1
-1,1
-1,0

Output

5
11
13

Explanation

There are 3 sets of coordinates in this test case (N=3). The coordinates are (1,1),(-1,1) and (-1,0). The corresponding primes at these positions are 5, 11, 13. Hence the output has these in 3 lines.
'''


