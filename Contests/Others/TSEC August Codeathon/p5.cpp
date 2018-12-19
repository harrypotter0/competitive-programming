#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll n, threshold, speed[100005] ;

ll answer(){
	
	ll left = 0, right = threshold + 1, mid ;
	
	while(right > left + 1){
		
		mid = (left + right) / 2 ;
        // logic part
		ll y = 0, z = 0 ;
		for(ll i = 0 ; i < n ; i++){
			if(speed[i] > mid) y += (speed[i] - mid) / 3 ;
			else z += (mid - speed[i] + 1) / 2 ; // +1 addition for ceil value
		}
		
		if(y >= z) left = mid ;
		else right = mid ;
		
	}
	
	return left ;
	
}

void solve(){
	
	cin >> n >> threshold ;
	for(ll i = 0 ; i < n ; i++) cin >> speed[i] ;
	
	cout << answer() << '\n' ;
	
}

int main(){
	
	ll t ; cin >> t ;
	while(t--) solve() ;
	
	return 0 ;
}