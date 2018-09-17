#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> myset{};
    myset.emplace(6);
    myset.emplace(2);
    myset.emplace(2);
    myset.emplace(7);
    myset.emplace(9);
    myset.emplace(1);
    for(auto it =myset.begin();it!=myset.end();++it)
        cout<<" "<<*it;
    int sum = 0;
    set<int>::iterator it;
    while(!myset.empty()){
        it = myset.begin();
        sum+=*it;
        myset.erase(it);
    }
    cout<<sum;
    return 0;
}
