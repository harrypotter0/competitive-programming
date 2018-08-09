/*2018-06-17-10.01.52*/
 
#include<bits/stdc++.h>
#define ll long long int
#define N 100010
using namespace std;
 
int main()
{
    int n;
    scanf("%d", &n);
    int mat[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
    int maxi = 1;
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++) if(mat[i][j]) cnt++;
        maxi = max(maxi, cnt + 1);
    }
    printf("%d\n", maxi);
    return 0;
}

