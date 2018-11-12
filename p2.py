
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
# template begins 
##################################### 
  
# import libraries for input/ output handling 
# on generic level 
import atexit, io, sys 
  
# A stream implementation using an in-memory bytes  
# buffer. It inherits BufferedIOBase. 
buffer = io.BytesIO() 
sys.stdout = buffer
  
# print via here 
@atexit.register 
def write(): 
    sys.__stdout__.write(buffer.getvalue()) 
  
##################################### 
# template ends 

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

# sys.setrecursionlimit(10000)

def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input().strip()
def readarr(n):
    return [map(int,list(readStr())) for i in xrange(n)]



n,k = readInts()
# arr = [0 for x in range(n+3)]
arr = [0]*(n+3)
# print arr
for i in range(1,n+1):
    s = readStr()
    arr[i] = int(s, 2)
for i in range(k):
    maxi = -1222121
    inp = readStrs()
    l = int(inp[0])
    r = int(inp[1])
    mm = int(inp[2],2)
    for j in range(l,r+1):
        av = arr[j]^mm
        if(maxi<av):
            maxi = av
            ind = j
    print(ind)

'''
5 4
100
101
1
1011
11
2 3 10
1 5 1100
3 5 1010
1 5 11100
'''