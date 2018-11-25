#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cal(ll* a ,  ll n, ll val , ll k){	
	ll count=0;
	for(int  i=0;i<n;i++){
		ll p = val/a[i];
		count+=p;		
	}
	if(count>=k)  
	    return true;	  
	else
	    return false;
	
}

int main() {
	ll t;
	cin>>t;
	while(t--){
    ll n,k;
    cin>>n>>k;
    ll* a = new ll[n]();
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    ll s = 1, e=100000000000000000;
    ll ans  = 1;
    while(s<=e){
        ll m = (s+e)/2;
        if(cal(a,n,m,k)){
            e=m-1;
            ans = m;
        }
        
        else
        s= m+1;
    }    
    cout<<ans<<endl;  
    }
}