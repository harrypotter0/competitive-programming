#include<bits/stdc++.h>
using namespace std;

void printDuplicateItems(int arr[], int n){
    unordered_set<int> intSet;
    unordered_set<int> duplicate;
    for(int i=0;i<n;i++){
        if(intSet.find(arr[i] == intSet.end()))
            intSet.insert(arr[i]);
        else
            duplicate.insert(arr[i]);
    }
    cout<<"Duplicate item are";
    unordered_set<int>::iterator itr;
    for(itr = duplicate.begin();itr!=duplicate.end();itr++)
        cout<<*itr<<" ";
}

