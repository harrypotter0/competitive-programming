#include<bits/stdc++.h>
using namespace std;
# define ll long long 

long long ans(long long a[],long long  n){
    long long i,meh=a[0],msf=a[0];
    for(int i=1;i<n;i++){
        meh=max(a[i],meh+a[i]);
        msf=max(msf,meh);
    }
    return msf;
}

bool prime[1000000+5];
vector<int>prime_store;
void SieveOfEratosthenes(int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
       prime_store.push_back(p);
        //   cout << p << " "; 
} 
  
int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long t;cin>>t;
    SieveOfEratosthenes(1000000);
    while(t--){
        long long n; cin>>n;
        cout<<prime_store[n-1]<<endl;
    }
	return 0;
}