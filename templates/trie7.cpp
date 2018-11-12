/*
// Sample code to perform I/O:
 
cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
struct node
{
    node *left[26];
    bool end;
    set<string>s1;
};
 
set<string>p1;
 
node *getnode()
{
    node *t=new node();
    t->end=false;
    for(ll i=0;i<26;i++)
        t->left[i]=NULL;
    return t;        
}
 
void insert1(string s, node *root)
{
    node *p=root;
    p->s1.insert(s);
    int len=s.length();
    for(int i=0;i<len;i++)
    {
            ll n;
            if(s[i]>=65&&s[i]<=90)
                    n=s[i]-65;
            else
                    n=s[i]-97;
            if(p->left[n]==NULL)
                    p->left[n]=getnode();
            p=p->left[n];
            p->s1.insert(s);
    }
    p->end=true;
}
 
void search(string s, node *root)
{
        node *p=root;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
                if(p->left[s[i]-97]==NULL)
                        return ;
                p=p->left[s[i]-97];        
        }
        // for(auto i=p->s1.begin();i!=->s1.end();i++)
        //         cout<<*i<<" ";
        p1=p->s1;
}
 
int main()
{
        ll n;
        cin>>n;
        node *root=getnode();
        while(n--)
        {
                string s;
                cin>>s;
                insert1(s,root);
        }
        
        ll q;
        //cout<<root->left[5]->s1.size()<<" ";
        cin>>q;
        while(q--)
        {
                string s;
                cin>>s;
                p1.erase(p1.begin(),p1.end());
                search(s,root);
                if(p1.size()==0){
                        cout<<"No suggestions\n";
                        insert1(s,root);
                }
                else
                {
                        for(auto it=p1.begin();it!=p1.end();it++)
                                cout<<*it<<"\n";
                        // insert1(s,root);        
                }
                        
        }
}
// Language: C++14