s=str(input())
c,d=0,0
for i in range(0,len(s)):
    if(s[i]=='*'):
        if(i%2==0):
            c=c+1
        else:
            d=d+1
    else:
        pass
print(pow(21,c)*pow(5,d)) 

