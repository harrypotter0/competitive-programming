import sys 
def readStrs():
    return raw_input().split()


# a = [int(s) for s in sys.argv[1:] if s.isdigit()]
a = []
a = [int(s) for s in readStrs() if s.isdigit()]
# print a
a = sorted(a)
if len(a)>0:
    print a[-1]
else:
    print "-1"
