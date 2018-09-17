#include<bits/stdc++.h>
using namespace std;

// O(n) complexity
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<n;i++)
        if (n%i==0)
            return false;
    return true;
}

// O(n^0.5) complexity
bool isPrime(int n){
    if (n<=1)return false;
    if (n<=3)return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6)
        if (n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

//Fermat's Method

int main(){
    isPrime(11)?cout<< "true\n":cout<<"false\n";
    isPrime(15)?cout<< "true\n":cout<<"false\n";
    return 0;
}

