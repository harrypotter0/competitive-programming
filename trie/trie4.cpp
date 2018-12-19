#include<bits/stdc++.h>
using namespace std;
 
/**------- ShortCuts----------*/
typedef long long             ll;
typedef unsigned long long    ull;
typedef double                db;
typedef long double           ldb;
typedef pair<int, int>        pii;
typedef pair<int, pii>        iii;
typedef vector<int>           vi;
typedef vector<pii>           vii;
typedef vector<iii>           viii;
 
/**------- Scanf----------*/
#define sf                 scanf
#define sfi(a)             scanf("%d", &a)
#define sfc(a)             scanf("%c", &a)
#define sfl(a)             scanf("%lld", &a)
#define sfu(a)             scanf("%llu", &a)
 
#define sfii(a, b)         scanf("%d %d", &a, &b)
#define sfll(a, b)         scanf("%lld %lld", &a, &b)
#define sfuu(a, b)         scanf("%llu %llu", &a, &b)
 
#define sfiii(a, b, c)     scanf("%d %d %d", &a, &b, &c)
#define sflll(a, b, c)     scanf("%lld %lld %lld", &a, &b, &c)
#define sfuuu(a, b, c)     scanf("%llu %llu %llu", &a, &b, &c)
 
/**------- Printf----------*/
#define pf                 printf
#define pfi(a)             printf("%d\n", a)
#define pfc(a)             printf("%c\n", a)
#define pfl(a)             printf("%lld\n", a)
#define pfu(a)             printf("%llu\n", a)
 
#define pfii(a, b)         printf("%d %d\n", a, b)
#define pfll(a, b)         printf("%lld %lld\n", a, b)
#define pfuu(a, b)         printf("%llu %llu\n", a, b)
 
#define pfiii(a, b, c)     printf("%d %d %d\n", a, b, c)
#define pflll(a, b, c)     printf("%lld %lld %lld\n", a, b, c)
#define pfuuu(a, b, c)     printf("%llu %llu %llu\n", a, b, c)
#define pnl                printf("\n")
 
/**--------Constant------------*/
#define mx5                100001
#define mx6                1000001
#define fr0(i, n)          for(int i=0; i<n; i++)
#define fr1(i, n)          for(int i=1; i<=n; i++)
#define FF                 first
#define SE                 second
#define all(x)             x.begin(), x.end()
#define INF                0x3f3f3f3f
#define eps                1e-8
#define PI                 acos(-1.0)
#define sq(x)              (x)*(x)
#define FasterIO           ios_base::sync_with_stdio(false);cin.tie(NULL)
#define UNIQ(a)            sort(all(a));a.erase(unique(all(a)),a.end())
#define mem(x, y)          memset(x, y, sizeof(x))
#define TestCases          int cases, tc; sfi(tc); \
                           for(cases=1; cases<=tc; cases++)
 
#define mxSize 2000001
#define sz     36
#define size   7
 
typedef struct node{
    int count;
    int isLeaf;
    struct node *child[sz];
} Node; Node *curP;
 
Node *newNode(){
    Node *cur = (Node *) malloc(sizeof(Node));
    cur->count = -1;
    cur->isLeaf = 0;
    for(int i=0; i<sz; i++)
        cur->child[i] = 0;
    return cur;
}
 
Node *insert(Node *root, char input[]){
    Node *cur = root; int id;
    for(int i=0; input[i]; i++){
        if(input[i] >= 'a' && input[i] <= 'z') id = input[i] - 'a';
        else id = input[i] - '0' + 26;
 
        if(cur->child[id] == NULL)
            cur->child[id] = newNode();
        cur = cur->child[id];
    }
    cur->count++;
    return root;
}
 
bool search(Node *root, char input[]){
    Node *cur = root; int id;
    for(int i=0; input[i]; i++){
        if(input[i] >= 'a' && input[i] <= 'z') id = input[i] - 'a';
        else id = input[i] - '0' + 26;
 
        if(cur->child[id] == NULL)
            return false;
        cur = cur->child[id];
    }
    curP = cur;
    return (cur->count != -1);
}
 
int main()
{
    int n; char input[mxSize], digit[10]; 
    Node *Root = newNode(); sfi(n);
    for(int i=0; i<n; i++){
        sf("%s", input);
        bool chk = search(Root, input);
        if(!chk){
            pf("%s\n", input);
            Root = insert(Root, input);
        } 
        else{
            Node *cur = curP;
            int start = cur->count;
            int len = strlen(input); 
            for(int j=start; ; j++){
                sprintf(digit, "%d", j);
                int idx = len;
                for(int k=0; digit[k]; k++)
                    input[idx++] = digit[k];
                input[idx] = '\0';
                if(!search(Root, input)) break;
                cur->count++;
            }
            pf("%s\n", input);
            Root = insert(Root, input);
        }
    } 
    return 0;
}
