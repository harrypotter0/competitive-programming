/*
Question : https://www.geeksforgeeks.org/samsung-interview-experience-set-30-campus/

Input1:
6 
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14

Input2:
5 
0 0 100 100 70 40 30 10 10 5 90 70 50 20

*/


#include <iostream>
#include <bits/stdc++.h>
#define dbgv(x) cout<< #x << " = " << x<<endl;


using namespace std;
#define MAXN 101
#define INF 1<<28

struct Point{
    int x,y;
    Point(int a, int b){
        x=a,y=b;
    }
    Point(){
        x=0,y=0;
    }
};

bool get_idx_val(int comb,int idx){
    return (comb>>idx)&1;
}

int set_idx_val(int comb, int idx){
    return comb|(1<<idx);
}

int abs(int n){
    return (n<0) ? (-1*n) : n;
}

int dist(Point &a, Point &b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}



int N;
Point delivery_points[MAXN];
int dp[1<<(10+2)][10];

int tsp(int visited_edge, int at){

    if( dp[visited_edge][at] != -1 )
        return dp[visited_edge][at];

    int min_cost=INF;
    bool atleast_one_visited=false;

    for(int i=1; i<=(N-2); i++){
        if( !get_idx_val(visited_edge,i) ){
            atleast_one_visited=true;
            min_cost = min( min_cost, dist(delivery_points[at],delivery_points[i]) + tsp(  set_idx_val(visited_edge,i), i ) );
        }
    }

    if(!atleast_one_visited){
        visited_edge = set_idx_val(visited_edge,N-1);
        return dp[visited_edge][at] =  dist(delivery_points[at],delivery_points[N-1]);
    }

    return dp[visited_edge][at]= min_cost;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        cin>>N;

        for(int i=0; i<(1<<10); i++)
            for(int j=0; j<10; j++)
                    dp[i][j] = -1;


        N+=2;

        cin>> delivery_points[0].x >>  delivery_points[0].y;
        cin>> delivery_points[N-1].x >>  delivery_points[N-1].y;

        for(int i=1; i<=(N-2); i++){
            cin>> delivery_points[i].x >> delivery_points[i].y;
        }

        cout<<"Test: "<< tsp( set_idx_val(0,0) , 0) <<endl;


}