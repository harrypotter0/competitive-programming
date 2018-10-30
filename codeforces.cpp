#include<bits/stdc++.h>
using namespace std;


# define ll long long 
# define pb push_back
# define mp make_pair
# define NO_OF_CHARS 256

long long maxsubarray(long long a[],long long  n){
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

bool perfectno(ll n ){
    ll sum =1;
    for(int i=2;i*i<=n;i++){
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
    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            max = i;
            n/=i;
        }
    }
    if(n>2)max = n;
    return max;
}

// void solve(int arr[], int n){
    
// }

ll binarySearch(vector<pair<int,int>>arr, int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
        if (arr[mid].first <= x and arr[mid].second>x)   
            return 0; 
        else if (mid+1<=r and arr[mid].first < x and arr[mid+1].first>x)   
            return arr[mid+1].first; 
        else if (arr[mid].first > x)  
            return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
   } 
   return -1; 
} 

// codeforces
int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    // SieveOfEratosthenes(1000000);
    int n,m;cin>>n>>m;
    int a,b;

	return 0;
}

