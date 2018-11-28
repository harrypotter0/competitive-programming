int prime[N6],sp[N6];
void sieve(){
    for(int i=1;i<N6;i++) prime[i]=1;
    for(int i=2;i*i<N6;i++){
        if(!prime[i]) continue;
        for(int j=i*2;j<N6;j+=i) {
            prime[j]=0;
            if(sp[j]==0) sp[j]=i;
        }
    }
    for(int i=1;i<N6;i++) if(!sp[i]) sp[i]=i;
}

int fac[10000005]; 
void init(){
    fac[0] = 1; 
    for (int i=1 ; i<=10000005; i++) 
    fac[i] = fac[i-1]*i%MOD; 
}  
int ncr(int n, int r){
	if(n<r)
	   return 0;
 	int val= fac[n];
	int val2 = (fac[n-r]*fac[r])%MOD;
	int res = (val*mpow(val2,MOD-2))%MOD;  
	return res;
}

