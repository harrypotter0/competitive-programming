/*
Input
5
20,-20,0,50,50
Output
7
*/
#include<stdio.h>
int main()
{
int a[100],m,i,k,j,c=0;
char b[50];
scanf("%d",&m);
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
if(i!=m-1)
scanf("%c",&b);
}
for(i=0;i<m-2;i++)
{
for(j=i+1;j<m-1;j++)
{
for(k=j+1;k<m;k++)
{
if(a[i]!=a[j]&&a[i]!=a[k]&&a[k]!=a[j])
c++; 
}
}
}
printf("%d\n",c);
return 0;
}
