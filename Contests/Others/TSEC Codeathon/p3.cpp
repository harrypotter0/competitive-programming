#include<iostream>
#include<string.h>
    
using namespace std ;
    
#define fast_io ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define ll long long
#define f(i, n) for(int i = 0 ; i < n ; i++)
    
ll dp[1000005] ;
    
ll max2(ll, ll) ;
    
int main(){    
    fast_io ;
    ll t_ ;
    cin >> t_ ;
    while(t_--){
        char s[1000005] ;
        cin >> s ;
        bool flag = true ;
        // All K's 
        for(ll i = 0 ; s[i] ; i++){
            if(s[i] == 'K'){
                flag = false ;
                break ;
            }
        }
        
        if(flag){
            cout << strlen(s) - 1 << endl ;
            continue ;
        } 
    
        for(ll i = 0 ; s[i] ; i++) dp[i] = 0 ;
        
        ll count ;
        ll maxval = count = 0 ;

        for(ll i = 0 ; s[i] ; i++){
            // count R's in the string 
            if(s[i] == 'R') count++ ;
            // check for K in the string 
            if(s[i] == 'K'){
                // 
                if(i == 0) dp[i] = 1 ;
                else dp[i] = dp[i - 1] + 1 ;
            } else if(s[i] == 'R'){
                if(i == 0) dp[i] = 0 ;
                else dp[i] = max2(0, dp[i - 1] - 1) ;
            }
            if(dp[i] > maxval) maxval = dp[i] ;
        }
        cout << maxval + count << endl ;
    }    
    return 0 ;
}
    
ll max2(ll a, ll b){
    if(a > b) return a ;
    else return b ;
} 
