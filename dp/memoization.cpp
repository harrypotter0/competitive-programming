#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll memo[10000];
ll countt(char ch[],ll i,ll n){
    if(memo[i]!=-1)
    return memo[i];
    ll j=i;
    ll sum=0;
    ll k=(ch[i]-'0');
    if(ch[i]=='\0'){
        if(k%2==0)
        return 1;
        else
        return 0;
    }
    if(k%2==0)
    sum++;
    sum=sum+countt(ch,j+1,n);
    memo[i]=sum;
    return sum;
}
int main(){
    fill(memo,memo+10000,-1);
    char ch[100000];
    cin>>ch;
    ll l=strlen(ch);
    for(ll i=0;i<l;i++){
        ll sum=0;
        cout<<countt(ch,i,l)-1<<" ";
    }
    return 0;
}