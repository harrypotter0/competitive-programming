n = int(raw_input()())
arr= []
c=0
for i in range(n):
    row = [int(i) for i in raw_input()().split(' ')]
    # arr.append(row)
    c = max(c, row.count(1))
print(c+1)
