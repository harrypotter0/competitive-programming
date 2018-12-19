#define watch(x) cout << (#x) << " is " << (x) << endl
// Class Definition
#include <bits/stdc++.h>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cout << #x << " = " << x << endl
#define dbga(arr, len) {cout << #arr << " = "; for (int _ = 0; _ < len; _++)\
cout << arr[_] << " "; cout << endl;}
#define dbgi(it) {cout << #it << " = "; for (const auto& _ : it)\
cout << _ << " "; cout << endl;}

class ThreePartSplit {
public:
    bool check(long long N){        
        bool f = true;
        string str = to_string(N);
        int n = str.length();
        for(int i=0;i<n-1;i++){
            if(i%2==0 and str[i]>=str[i+1]){
                f= false;
                break;
            }
            else if(i%2==1 and str[i]<=str[i+1]){
                f= false;
                break;
            }            
        }
        return f;
    }
    int split(long long  a, long long  b) {
        int count = 0;
		for(long long i=sqrt(a);i<=sqrt(b)){
            if(i*i>=a and i*i<=b and check(i*i)){
                count+=1;                
            }
        }
			
    }
    return count;
};



signed main(){
    ThreePartSplit sol;
    cout<<(sol.split(1, 64));
    cout<<(sol.split(50, 60));
    cout<<(sol.split(121, 121));
    cout<<(sol.split(5679, 1758030));
    cout<<(sol.split(1304164, 2000000));
}
