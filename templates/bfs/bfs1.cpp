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

ll digSumm(ll n) 
{ 
    if (n == 0)  
       return 0; 
    return (n % 9 == 0) ? 9 : (n % 9); 
} 

ll digSum1(ll n) 
{ 
    ll sum = 0; 
    while(n > 0 ) 
    { 
        sum += n % 10; 
        n /= 10; 
    } 
    return sum; 
} 

// for count check
ll digcount(ll n) 
{ 
    ll sum = 0,count=1; 
    while(n > 0 || sum > 9) 
    { 
        if(n == 0) 
        { 
            n = sum; 
            sum = 0; 
            count+=1;
        } 
        sum += n % 10; 
        n /= 10; 
    } 
    return count; 
} 

// A node of BFS traversal 
struct node 
{ 
	ll val; 
	ll level; 
}; 

// minOperations(val, mini, m);
ll minOperations(ll x, ll y, ll add) 
{ 
	set<int> visit; 

	queue<node> q; 
	node n = {x, 0}; 
	q.push(n); 
	while (!q.empty()) 
	{ 
		node t = q.front(); 
		q.pop(); 

		if (t.val == y) 
			return t.level; 

		visit.insert(t.val); 

		if (t.val+add == y || digSum1(t.val) == y) 
			return t.level+1; 

		if (visit.find(t.val+add) == visit.end()) 
		{ 
			n.val = t.val+add; 
			n.level = t.level+1; 
			q.push(n); 
		} 

		if (visit.find(digSum1(t.val)) == visit.end()) 
		{ 
			n.val = digSum1(t.val); //sum of digits 
			n.level = t.level+1; // no of loops
			q.push(n); 
		} 
	} 
} 


// codechef
int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;cin>>t;
    // SieveOfEratosthenes(1000000);
    while(t--){
        ll mini = 1e9, op =0;
        ll n,m;cin>>n>>m;
        ll ans = n;
        ll val = n;
        ll optimal;
        ans = n%9;
        int f =0;
        for(ll i=0;i<200;i++){
            if(ans==0)ans =9;
            if(ans<mini){
                mini = ans;
                op = i;
                optimal = n;
            }
            ans = (n%9+m%9)%9;
            n = n%9+m%9;
        }
        ll add2 = minOperations(val, mini, m);
        cout<<mini<<" "<<add2<<endl;
    }
	return 0;
}

