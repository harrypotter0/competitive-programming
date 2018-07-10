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

import math
import calendar
def readInts():
    return list(map(int, raw_input().strip().split(',')))
def readInt():
    return int(raw_input())
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()
def readnumbertolist():
    a=[int(i) for i in list(raw_input())]
    return a
def findpermute(word):
    perms = [''.join(p) for p in permutations(word)]
    perms = list(set(perms))
    return perms
def findsubsets(S,m):
    return list(set(itertools.combinations(S, m)))
mod = 1009
n,p,q = readInts()
arr =readInts()
elem = []
count = 0
for i in range(1,n+1):
    elem.append(findsubsets(arr,i))
for i in elem:
    for j in i:
        f1,f2= 0,0
        for k in j:
            if k>p*q and k%p==0 and k%q==0:
                # print j
                count+=1
                count%=mod
                break
            if k%p==0:
                f1 =1
            if k%q==0:
                f2 =1
            if f1 and f2:
                # print j
                count+=1
                count%=mod
                break                  
print count%mod

'''
Input

4,5,7
5,49,10,27

Output
6

Example 2

Input

4,11,13
3,7,12,13

Output

0
'''
