#include <bits/stdc++.h>
#define ll long long
#define mx  100005
#define mod 1000000009
#define lim 100
using namespace std;
 
int seg[mx];
 
int main(){
	ios_base::sync_with_stdio(false);
	memset(seg,0,sizeof(seg));
 
    int n,m;cin>>n>>m;
 
    while(m--)
	{
		int l,r;cin>>l>>r;l--,r--;
		seg[l]++,seg[r+1]--;
	}
 
	for(int i=1;i<n;i++)seg[i]+=seg[i-1];
	sort(seg,seg+n);
 
	int q;cin>>q;
 
	while(q--)
	{
		int k;cin>>k;
		int low=lower_bound(seg,seg+n,k)-seg;
		low++;
		cout<<n-low+1<<"\n";
	}
	return 0;
}
