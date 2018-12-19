#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree< pair<int, int>,null_type,less<pair<int, int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
    ordered_set X;
    int n,d,count=0,median;
    cin>>n>>d;
    vector<int>arr(n);
    for(int i=0;i<n;i++)    cin>>arr[i];
    
    for(int i=0;i<n;i++)
    {
        if(i>=d)
        {
            if(d&1)  median=((X.find_by_order(d/2))->first)*2;
            else    median=((*X.find_by_order(d/2)).first+(*X.find_by_order(d/2 -1)).first);
            
            if(arr[i]>=(median))  count++;
            X.erase({arr[i-d],i-d});
        }
        X.insert({arr[i],i});
    }
    cout<<count;
}