#include<bits/stdc++.h>
using namespace std;

# define ll long long 
# define pb push_back
# define mp make_pair
# define NO_OF_CHARS 256

long long maxsubarray(long long a[],long long  n){
    long long i,meh=a[0],msf=a[0];
    for(ll i=1;i<n;i++){
        meh=max(a[i],meh+a[i]);
        msf=max(msf,meh);
    }
    return msf;
}

bool prime[1000000+5];
vector<ll>prime_store;
void SieveOfEratosthenes(ll n) 
{ 
    memset(prime, true, sizeof(prime)); 
    for (ll p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (ll i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (ll p=2; p<=n; p++) 
       if (prime[p]) 
       prime_store.push_back(p);
        //   cout << p << " "; 
} 

bool perfectno(ll n ){
    ll sum =1;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            sum+=(i+n/i);
        }
    }
    if(sum==n && n!=1)return true;
    return false;
}  

ll maxprimefactor(ll n){
    ll max = -1;
    while(n%2==0){
        max=2;
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){
            max = i;
            n/=i;
        }
    }
    if(n>2)max = n;
    return max;
}

ll binarySearch(vector<pair<ll,ll>> vect, ll target, ll length) 
{ 

	ll low = vect[0].first; 
	ll high = vect[length-1].first; 
	while (low < high) { 

		ll f = 0, sum = 0; 

		ll mid = low + (high - low) / 2; 
        // cout<<mid<<" <<mid ";
		for (ll i = length - 1; i >= 0; i--) { 

			if (vect[i].first > mid) { 
			    ll diff = vect[i].first-mid;
			    if(diff%vect[i].second==0)
			        sum+=diff/vect[i].second;
			    else
			        sum+=(diff/vect[i].second)+1;
			} 
            // cout<<sum<<" <<sum ";            
			if (sum > target) { 
				f = 1; 
				low = mid+1; 
				break; 
			}

		}
		cout<<endl;

		if (f == 0) 
			high = mid; 
	} 

	// returning the maximum cut off length 
	return low ; 
} 


// codechef
int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    // SieveOfEratosthenes(1000000);
        ll sum = 0;
        ll n,m,f;cin>>n>>m;
        ll a[n],b[n];
        
        // inputs
        for(ll i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        for(ll i=0;i<n;i++){
            cin>>b[i];
            a[i]*=b[i];
        }
        vector<pair<ll, ll >> vect;
        for(int i=0;i<n;i++){
            vect.push_back( make_pair(a[i],b[i]) ); 
        }
        sort(vect.begin(), vect.end()); 
        
        if(sum<=m){
            cout<<0<<endl;
        }
        else{
            cout<<binarySearch(vect,m,n)<<endl;
        }

	return 0;
}

