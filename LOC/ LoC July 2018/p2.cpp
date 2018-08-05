#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1000005;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define M 1000000007
    
int Arr[N],size[N];
    
void initialize( int Arr[ ], int N)
{
for(int i = 0;i<N;i++){
Arr[ i ] = i ;
size[ i ] = 1;
}
}
    
int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i){
        Arr[i] = Arr[Arr[i]]; 
        i = Arr[i]; 
    }
return i;
}
    
void weighted_union(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ]){
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
    else{
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }
}
    
#undef int
int main(){
#define int long long int
    
int n;
cin>>n;
    
initialize(Arr,n+1);
    
int q;
cin>>q;
while(q--)
{
    int x;
    cin>>x;
    if(x==0)
    {
        int a,b;
        cin>>a>>b;
        weighted_union(Arr,size,a,b);
    }
    else
    {
        int a,b;
        cin>>a>>b;
        if(root(Arr,a)==root(Arr,b))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
} 