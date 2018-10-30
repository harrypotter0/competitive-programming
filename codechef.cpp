/////////////// More Shortcuts //////////////////////////

// for rounding to nearest integer
int ans = (int)((double)d + 0.5); 
// index--; if (index < 0) index = n - 1;
index = (index + n - 1) % n; 

/////////////////////////////////////////////////////////
int multiply(int x, int res[], int res_size) { 


// Initialize carry 
int carry = 0; 

// One by one multiply n with 
// individual digits of res[] 
for (int i = 0; i < res_size; i++) { 
	int prod = res[i] * x + carry; 

	// Store last digit of 
	// 'prod' in res[] 
	res[i] = prod % 10; 

	// Put rest in carry 
	carry = prod / 10; 
} 

// Put carry in res and 
// increase result size 
while (carry) { 
	res[res_size] = carry % 10; 
	carry = carry / 10; 
	res_size++; 
} 
return res_size; 
} 

// This function finds 
// power of a number x 
void power(int x, int n) { 
int res[MAX]; 
int res_size = 0; 
int temp = x; 

// Initialize result 
while (temp != 0) { 
	res[res_size++] = temp % 10; 
	temp = temp / 10; 
} 

// Multiply x n times 
// (x^n = x*x*x....n times) 
for (int i = 2; i <= n; i++) 
	res_size = multiply(x, res, res_size); 

// cout << x << "^" << n << " = "; 
for (int i = res_size - 1; i >= 0; i--) 
	cout << res[i]; 
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

string multiplyStrings(string str1, string str2){
    int sign = 1;
    if (str1[0] == '-') {
      sign = sign * (-1);
      str1.erase(str1.begin());
    }
   
    if (str2[0] == '-') {
      sign = sign * (-1);
      str2.erase(str2.begin());
    }

    int m=str1.length(),n=str2.length();

    int pos[m+n+1]={0};
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int mul=(str1[i]-'0')*(str2[j]-'0');
            int p1=i+j,p2=i+j+1;
            int sum=abs(mul)+abs(pos[p2]);
            pos[p1]+=sum/10;
            pos[p2]=sum%10;
        }
    }
    string sb;
    for(int i=0;i<m+n;i++)if(!(sb.length()==0 and pos[i]==0))sb+=to_string(pos[i]);
    if(sb.length()==0)return "0";
    if (sign == -1)
        sb.insert(sb.begin(), '-');
    return sb;
}



ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res;
}

ll binomialCoeff(ll n, ll k) 
{ 
    if(0<=k and k<=n){
        ll nt = 1;
        ll dt = 1;
        ll temp=n;
        for(ll t=1; t<=min(n-k,k); t++){
            nt= (nt%MOD*temp%MOD)%MOD;
            // nt%=MOD;
            dt= (dt%MOD*t%MOD)%MOD;
            // dt%=MOD;
            temp-=1;
        }
        return (nt%MOD*fast_exp(dt,MOD-2)%MOD)%MOD;
    }
    else
        return 0;
} 

long long maxsubarray(long long a[],long long  n){
    long long i,meh=a[0],msf=a[0];
    for(ll i=1;i<n;i++){
        meh=max(a[i],meh+a[i]);
        msf=max(msf,meh);
    }
    return msf;
}

string addbinary(string a, string b){
    string res="";
    int s=0;
    int i=a.size()-1,j=b.size()-1;
    while(i>=0 || j>=0||s==1){
        s+=((i>=0)?a[i]-'0':0);
        s+=((j>=0)?b[j]-'0':0);
        res = char(s%2+'0') + res;
        s/=2;//compute carry 
        i--;j--;        
    }    
    return res;
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

double distance(int x1, int y1, int x2, int y2) 
{ 
    // Calculating distance 
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
} 

int binary(int arr[], int l, int r, int x){
    if(r>=l){
        int mid = l+(r-l)/2;
        cout<<arr[mid]<<" <<<<mid ";
        if(arr[mid]==x) 
            return mid+1;
        else if (arr[mid]<x)
            return binary(arr, mid+1, r, x);
        else 
            return binary(arr, l, mid-1, x);
        
    }
    return -1;
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

