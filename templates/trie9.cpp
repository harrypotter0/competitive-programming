//For higher stack size use g++ -O2 -std=c++11 -Wall -Wl,--stack=268435456 a.cpp -o a.exe in cmd
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second

using namespace std;

string ar[100001];
int padar[100001];

//Trie taken and modified from ---- https://www.geeksforgeeks.org/trie-insert-and-search/

const int ALPHABET_SIZE = 2;    //Alphabet Size is 2 as strings are binary
  
// trie node 
struct TrieNode 
{
    struct TrieNode *children[ALPHABET_SIZE];   //Stores the children of node
    struct TrieNode *nxt;   //Stores the next node . Used for compression. If a node has both left and right child nxt points to itself
    vector<int> v;  // Stores index of all strings that pass through the node 
    int depth;  //Depth of the node(string) wherein depth refers to index of the element of the string you are traversing. 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{
    struct TrieNode *pNode =  new TrieNode; 
    pNode->nxt=NULL;
    pNode->depth=0;
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
int idx;
void insert(struct TrieNode *root, string key,int dep)  //trie insertion of string
{
    struct TrieNode *pCrawl = root; 
    int index,flag=0;
    for (int i = 0; i < key.length();++i)
    {
        //cout<<i<<"...."<<key[i]<<endl;
        int index=key[i]-'0';
        if(!pCrawl->children[index])
        {
            pCrawl->children[index]=getNode();
            pCrawl->children[index]->depth=dep+i+1;
        }
        pCrawl=pCrawl->children[index];
    }
    pCrawl->v.pb(idx);      //Add index only to leaf
}

map<int,struct TrieNode *> mp;

void insert2(struct TrieNode *root,int len)     //Insert maxi number of 0's. Maxi = max length of input string
{
    mp[0]=root;
    for(int i=1;i<=len;++i)
    {
        root->children[0]=getNode();
        root=root->children[0];
        mp[i]=root;     // add it to map for easy access to the ith zero
    }
}

void dfs(struct TrieNode *root)     //DFS is used for trie compression
{
    if(!root->children[0] && !root->children[1])        // If both children are not present(leaf) node mark nxt as the node itself
    {
        root->nxt=root;
        return;
    }

    if(root->children[0])   // If only child 0 is present
    {
        root->children[0]->depth=root->depth+1;
        dfs(root->children[0]);
    }
    if(root->children[1])   // If only child 1 is present
    {
        root->children[1]->depth=root->depth+1;
        dfs(root->children[1]);
    }

    if((!root->children[0]) || root->children[0]->nxt==NULL || root->children[0]->nxt->v.size()==0)     //Check if child 0 is not present or it is one of the padding 0's that have been added but not used(size = 0)
    {
        root->children[0]=NULL;     //Assign child 0 as NULL
        if(!root->children[1])      //Check if child 1 is also NULL
        {
            root->children[1]=NULL; 
            root->nxt=root; //Since both children are NULL mark nxt as the node itself
            return;
        }
        root->nxt=root->children[1]->nxt;   //Mark node as child 1's nxt
        return;
    }
    if((!root->children[1]) || root->children[1]->nxt->v.size()==0 || root->children[1]->nxt==NULL) //Check if child 1 is not present or it is empty(never occurs I guess but I copy pasted above if and modified it)
    {
        root->children[1]=NULL;
        if(!root->children[0])  //Check if child 0 is also NULL
        {
            root->children[0]=NULL;
            root->nxt=root; //Since both children are NULL mark nxt as the node itself
            return;
        }
        root->nxt=root->children[0]->nxt;
        return;
    }
    root->v.assign(root->children[0]->nxt->v.size()+root->children[1]->nxt->v.size(),-1);   //Both children are not 0
    merge(root->children[0]->nxt->v.begin(),root->children[0]->nxt->v.end(),root->children[1]->nxt->v.begin(),root->children[1]->nxt->v.end(),root->v.begin());     //Merge both children's indices into root
    root->nxt=root;
}
  

int L,R;
int search(struct TrieNode *root, string key,int pad)   //Searching for string named key with padding as pad to make it as equal length as input strings
{ 
    struct TrieNode *pCrawl = root; 
    int index,flag=0,ndep;
    while(true)
    {
        
        if(!pCrawl->children[0] && !pCrawl->children[1])    //Leaf node
            break;
        ndep=pCrawl->depth; //Depth of node
        
        if(ndep < pad)  //Check if depth is less than padding. Since padding consists of 0's preferred index is 1
        {
            index=1;
        }
        else    //Find preferred xor value for current character in question. For character 1 it is 0 and vice versa. Current character is ndep-pad.
        {
            index = key[ndep-pad] - '0';
            index=1-index;
        }
        if (!pCrawl->children[index])   //Check if preferred child is not present. If not present we are forced to go to the other child.
        {
            pCrawl=pCrawl->children[1-index]->nxt;
        }
        else    // If preferred child is present find if it has some element in [L,R] using bsrch
        {
            int pos=lower_bound(pCrawl->children[index]->nxt->v.begin(),pCrawl->children[index]->nxt->v.end(),L)-pCrawl->children[index]->nxt->v.begin();
            
            if(pos>=pCrawl->children[index]->nxt->v.size() || pCrawl->children[index]->nxt->v[pos]>R)
            {
                pCrawl=pCrawl->children[1-index]->nxt;
            }
            else    //Else go to the other child
            {
                pCrawl=pCrawl->children[index]->nxt;
            }
        }
    }
    int pos=lower_bound(pCrawl->v.begin(),pCrawl->v.end(),L)-pCrawl->v.begin();     // Find position of first element in [L,R]
    return pCrawl->v[pos];  //Return element
} 
  


int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    T=1;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--)
    {
        int n,q,i,j,l,r;
        cin>>n>>q;
        string ar[n];
        int maxi=0,pad;
        struct TrieNode *root = getNode();
        for(i=0;i<n;++i)
        {
            cin>>ar[i];
            maxi=max(maxi,(int)ar[i].length());     //Find max length of input strings
        }
        insert2(root,maxi); //Pad maxi 0's.
        for(i=0;i<n;++i)
        {
            idx=i+1;
            pad=maxi-ar[i].length();
            insert(mp[pad],ar[i],pad);  //Insert strings
        }
        dfs(root);  //Compression
        //cout<<root->v.size()<<endl;
        string s;
        int st;
        while(q>0)
        {
            cin>>l>>r>>s;
            L=l,R=r;
            if(s.length()>maxi) // If query string length is higher than trie length(length of elements in trie) trim
            {
                s=s.substr(s.length()-maxi);
                pad=0;
            }
            else    // Pad it otherwise
            {
                pad=maxi-s.length();
            }
            
            cout<<search(root,s,pad)<<endl; //Search for the element
            --q;
        }
    }
    return 0;
}
