#include<bits/stdc++.h>
#include<vector>
using namespace std;
// #define ll long long int

long long int XorPairCount_map(vector<long long int> arr, int x){
    long long int result = 0;
    unordered_map<int,int>m;
    for (auto i = arr.begin(); i!=arr.end(); i++) { 
        long long int curr_xor = x^*i;
        if(m.find(curr_xor)!=m.end())
            result += m[curr_xor];
        m[*i]++;
    }
    return result;
}

long long int countXorPair(vector<long long int>arr) 
{ 
  long long int odd = 0, even = 0; 
  
    for (auto i = arr.begin(); i!=arr.end(); i++) { 
        if (*i % 2 == 0) 
            even++; 
        else
            odd++; 
    } 
    long long int n = arr.size();
    return n*(n-1)/2-odd * even; 
} 
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  long long int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
    long long n;
    cin >> n;

    long long input;
  long long int count1 = 0;
    vector<long long> even, odd, vec;
    for (int j = 0; j < n; j++) {
            cin >> input;
            vec.push_back(input);
            if (input==1)
                count1+=1;
            if (input % 2 == 0) {
                even.push_back(input);
            } else {
                odd.push_back(input);
            }
    }
    // sort( vec.begin(), vec.end() );
    // vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
    long long int answer = 0,a1=0,b1=0;
    // for (auto it = vec.begin(); it!=vec.end(); it++) 
    //     cout<<" "<<*it;
    // cout<<endl;

    a1 = countXorPair(vec);
    b1 = XorPairCount_map(vec,2)+XorPairCount_map(vec,0) ;
    // cout<<XorPairCount_map(vec,0)<<" " <<XorPairCount_map(vec,1)<<" "<<XorPairCount_map(vec,2)<<endl;
    // b1 = countXorPair(odd);
    answer = a1-b1;

    cout << answer << endl;
    }
 return 0;
}