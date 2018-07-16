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


# m = 329885391853
# lim =  prelongfact(m)

mod = 10 ** 9 + 7
# fact=[1]
# for i in xrange(1,100001):
#     fact.append(((arr[i-1]%mod)*(i%mod))%mod)
# for i,j in product(xrange(R),xrange(C)):
# print "Case #{}: {}".format(i+1,ans)
import os
cdir = os.getcwd()
cdir+="/"
filename = "interception.txt"
text_file = open(cdir+filename, "r")
lines = text_file.readlines()
text_file.close()
# print(lines[0])
file1 = open("{}".format((filename[:-4]+".out").replace("_", "")), "w")#append mode
count = 0
c1 =0
while c1<len(lines)-1:
    c1+=1
    count+=1
    p = int(lines[c1])
    arr = []
    print c1,lines[c1]
    for i in range(p+1):
        c1+=1
        print c1,lines[c1]
        arr.append(lines[c1].strip())
    print arr
    if p<=1:
        file1.write("Case #{}: {}\n".format(count,"1"))
        file1.write("{}\n".format("0.0")) 
    else:
        file1.write("Case #{}: {}\n".format(count,"0"))
    # print c1
file1.close()

'''

2
1
1
1
4
9
0
-6
2
-2
Case #1: 1
0.0
Case #2: 0
'''

