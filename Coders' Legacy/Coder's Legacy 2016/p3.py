# your code goes here
from sys import stdin, stdout
n = int(stdin.readline())
ps, qs = map(int, stdin.readline().strip().split(' '))
m = int(stdin.readline())
pb, qb = map(int, stdin.readline().strip().split(' '))
s = ps % qs
b = pb % qb
bs = [0] * 101
bs[ps % qs] += 1
bb = [0] * 101
bb[pb % qb] += 1
for i in range(1, n):
	s = (s*ps)%qs
	bs[s] += 1
for i in range(1, m):
	b = (b*pb)%qb
	bb[b] += 1
nums = min(n, m)
numb = min(n, m)
cs = 0
cb = 0
for i in range(100, -1, -1):
	if bs[i] and nums:
		cs += i*(min(bs[i], nums))
		nums -= min(bs[i], nums)
	if bb[i] and numb:
		cb += i*(min(bb[i], numb))
		numb -= min(bb[i], numb)
a = cs - cb
stdout.write("%.1f" % (float(a) / float(max(n, m)))) 
