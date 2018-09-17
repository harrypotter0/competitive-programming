#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned ll ull;
typedef pair<int,int> pii;
#define DISP(x)     cout << #x << ": " << x << endl;

struct Point{
    public:
        int x,y,dist;
        Point(int _x=0,int _y=0,int _dist=0){
            x=_x;y=_y;dist=_dist;
        }
        bool operator<(const Point &p) const{
            if(p.x==x)
                return y<p.y;
            else
                return x<p.x;
        }
};

bool isprime(ull n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n<=30 && rem[n%30]) return false;
    if(MR(2, n))
}

inline ull

int solve(int x,int y){
    map<Point,bool> vis;
    queue<Point, list<Point>> q;
    int i,tx,ty;
    Point cur;

    q.push(Point(x,y));
    while(!q.empty()){
        cur = q.front();q.pop();
        tx=cur.x;ty=cur.y;
        if(vis[cur]) continue;
        vis[cur] = true;
        if(isprime(coordToNum(cur)))
            return cur.dist;
        q.push(Point(tx+1,ty,cur.dist+1));
        q.push(Point(tx-1,ty,cur.dist+1));
        q.push(Point(tx,ty+1,cur.dist+1));
        q.push(Point(tx,ty-1,cur.dist+1));
    }
    return 0;
}

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<"\n";
    }
	return 0;
}

/*
Input:
8
0 0
1 0
1 1
0 1
3 3
-3 -3
-1 2
0 -3

Output:
1
1
0
0
1
1
2
2

*/