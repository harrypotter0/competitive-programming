#include<bits/stdc++.h>
using namespace std;


# define ll long long 
# define pb push_back
# define mp make_pair
# define NO_OF_CHARS 256


double distance(ll x1, ll y1, ll x2, ll y2) 
{ 
    // Calculating distance 
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
} 

// codechef
int main()
 {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    // SieveOfEratosthenes(1000000);
    // ll t;cin>>t;
    // while(t--){
        ll n,m,f;cin>>n>>m;
        double a[n],b[n],r[n];
        for(ll i=0;i<n;i++){
            cin>>a[i]>>b[i]>>r[i];
        }
        double mini, maxi;
        ll st[10000001]={0}, end[10000001]={0};
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                double dist = distance(a[i],b[i],a[j],b[j]);
                // concentric circles
                ll f =0;
                if(dist==0){
                    mini = abs(r[i]-r[j]);
                    maxi = (r[i]+r[j]);f =1;
                }
                // touch internally
                else if(dist==abs(r[i]-r[j])){
                    mini = 0;
                    maxi = 2*max(r[i],r[j]);f=2;
                }
                // touch externally 
                else if(dist==(r[i]+r[j])){
                    mini = 0;
                    maxi = 2*(r[i]+r[j]);f=3;
                }
                // inside circle without touch
                else if(dist<abs(r[i]-r[j])){
                    mini = max(r[i],r[j])-min(r[i],r[j])-dist;
                    maxi = 2*max(r[i],r[j])-(max(r[i],r[j])-min(r[i],r[j])-dist);f=6;
                }
                // intersect 
                else if(dist<(r[i]+r[j])){
                    mini = 0;
                    maxi = dist + (r[i]+r[j]);f=4;
                }
                // disjoint circles 
                else if(dist>(r[i]+r[j])){
                    mini = dist - (r[i]+r[j]);
                    maxi = dist + (r[i]+r[j]);f=5;
                }

                // if(mini<=distt and distt<=maxi){
                //     count+=1;
                // }
                
                // cout<<i+1<<" "<<j+1<<" "<<mini<<" "<<maxi;
                // if(f==0)cout<<" Not Possible "<<endl;
                // if(f==1)cout<<" concentric circles "<<endl;
                // if(f==2)cout<<" touch llernally "<<endl;
                // if(f==3)cout<<" touch externally "<<endl;
                // if(f==4)cout<<" llersect "<<endl;
                // if(f==5)cout<<" disjoll circles "<<endl;
                // if(f==6)cout<<" inside circle without touch "<<endl;
                st[(int)ceil(mini)]++;
                end[(int)floor(maxi)]++;
                // cout<<mini<<" "<<maxi<<" "<<(int)(mini)<<" "<<(int)(maxi)<<" "<<endl;
            }
        }
            // cout<<"**********************"<<endl;

        ll c[10000001]={0};c[0]=st[0];
        for(ll i=1;i<10000001;i++){
            c[i] = st[i]-end[i-1] + c[i-1];
            // if(i==1)cout<<0<<" "<<c[0]<<" "<<st[i-1]<<" "<<end[i-1]<<endl;
            // if(c[i]>0)cout<<i<<" "<<c[i]<<" "<<st[i]<<" "<<end[i]<<endl;
        }

        while(m--){
            ll distt;cin>>distt;
            // ll count = 0;
            
            cout<<c[distt]<<endl;
            // cout<<"######################"<<endl;
        }
        
    // }
	return 0;
}

