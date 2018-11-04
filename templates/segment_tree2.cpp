#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

clock_t first_attempt = clock();
inline void cek_time(){
	clock_t cur = clock()- first_attempt;
	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
}
inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of template


const int maxm = 1e6+6;
const int maxn = 1e5+5;
struct node{
	int v;
	node *l,*r;
	node(int a,node *b,node *c):v(a),l(b),r(c){}
}*root[maxn];

int l,r,v;
node *insert(node *a,int ki,int ka){
	if(ka<l || ki>l)return a;
	if(ki==ka)return new node(a->v+v,NULL,NULL);
	else{
		int mid = (ki+ka)>>1;
		return new node(a->v+v,insert(a->l,ki,mid),insert(a->r,mid+1,ka));
	}
}

int query(node *a,node *b,int ki,int ka){
	if(ka<l || ki>r)return 0;
	if(l<=ki && ka<=r)return b->v - a->v;
	int mid = (ki+ka)>>1;
	return query(a->l,b->l,ki,mid) + query(a->r,b->r,mid+1,ka);
}

int n,q;
int prime[maxm];

int main(){
	rep(k,1,maxm)prime[k] = k;
	rep(k,2,maxm)if(prime[k]==k){
		for(int i = 2*k;i<maxm;i+=k)prime[i]= k;
	}
	scanf("%d",&n);
	
	root[0] = new node(0,NULL,NULL);
	root[0]->l = root[0]->r = root[0];
		
	rep(k,1,n+1){
		int a;
		scanf("%d",&a);
		
		int x = k-1;
		while(a>1){
			l = prime[a], v = 1;
			
			root[k] = insert(root[x],1,maxm);
			x = k;
			a/=prime[a];
		}
	}
	
	scanf("%d",&q);
	while(q--){
		int ki,ka;
		scanf("%d%d%d%d",&ki,&ka,&l,&r);
		printf("%d\n",query(root[ki-1],root[ka],1,maxm));
	}
	return 0;
}

