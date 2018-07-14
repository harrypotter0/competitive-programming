#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
   ll t;cin>>t;
   while(t--){
    ll A,B;cin>>A>>B;
    ll b=2*(A+B);
    ll c=A*B;
    double X1=(b+(double)sqrt((b*b)-12*c))/6;
    double X2=(b-(double)sqrt((b*b)-12*c))/6;
    ll x1=(ll)round(X1);
    ll x2=(ll)round(X2);
    if(x1<x2)
        cout<<x1<<" "<<x1*(A-x1)*(B-x1)<<endl;
        else cout<<x2<<" "<<x2*(A-x2)*(B-x2)<<endl;
   }
    return 0;
}