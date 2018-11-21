#include <list>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct TrieNode
{
	int leaf=0;
	struct TrieNode* child[26]={NULL};
}trie;

void add(string s, trie* t)
{
	trie* temp=t;
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<" ";
		if(!temp->child[s[i]-'a'])
			temp->child[s[i]-'a']=new trie;
		temp=temp->child[s[i]-'a'];
	}
	temp->leaf++;
	cout<<"\tdone\n";
}

bool search(string s, trie* t)
{
	trie* temp=t;
	for(char x:s)
	{
		cout<<x<<" ";
		if(temp->child[x-'a'])
			temp=temp->child[x-'a'];
		else
			return false;
	}
	return true;
}

int main()
{
	trie *head=new trie;
	add("amazing",head);

	cout<<search("amazi",head);
}