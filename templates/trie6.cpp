#include <iostream>
#include <map>
 
using namespace std;
 
struct Trie {
    map<char,Trie*> child;
    bool isEnd;
 
    Trie()
    {
        isEnd=false;
    }
};
 
void insrt(Trie *root,string s)
{
    Trie *curr=root;
    for(int i=0;i<s.length();i++)
    {
        Trie *node = curr->child[s[i]];
        if(!node)
        {
            node=new Trie();
            curr->child[s[i]]=node;
        }
        curr=node;
    }
    curr->isEnd=true;
}
 
Trie* search_(Trie *root,string s)
{
    Trie *curr=root;
    for(int i=0;i<s.length();i++)
    {
        if(!curr->child[s[i]])
        {
            return NULL;
        }
        curr=curr->child[s[i]];
    }
    return curr;
}

void display(Trie *root,char s1[],int level,string str)
{
    if(root->isEnd)
    {
        s1[level]='\0';
        cout<<str+s1<<"\n";
    }
    for(auto it=root->child.begin();it!=root->child.end();it++)
    {
        s1[level]=it->first;
        display(root->child[it->first],s1,level+1,str);
    }
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    Trie *root=new Trie();
    while(n--)
    {
        string s;
        cin>>s;
        insrt(root,s);
    }
    int q;
    cin>>q;
    while(q--)
    {
        string str;
        cin>>str;
        Trie *temp = search_(root,str);
        if(!temp)
        {
            insrt(root,str);
            cout<<"No suggestions\n";
        }
        else
        {
            char s1[100005];
            display(temp,s1,0,str);
        }
    }
    return 0;
}
