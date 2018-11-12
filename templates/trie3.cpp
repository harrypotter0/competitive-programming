#include<bits/stdc++.h>
#include<string>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHARACTERS 26
#define CHAR_TO_INDEX(c) (int)c - (int)'a'
 
using namespace std;
 
struct TrieNode
{
	struct TrieNode *children[CHARACTERS];
	bool isLeaf; 
};
 
struct TrieNode *getNode()
{
	struct TrieNode *myNode = new TrieNode;
	myNode->isLeaf = false;
 
	for(int i = 0;i < CHARACTERS;i++)
		myNode->children[i] = NULL;
 
	return myNode;
}
 
void Insert(struct TrieNode *root, string key)
{
	int len = key.length();
	struct TrieNode *myNode = root, *temp = NULL;
	char letter;
	int index;
 
	for(int i = 0;i < len;i++)
	{
		letter = key[i];
		index = CHAR_TO_INDEX (letter);
		if(myNode->children[index] == NULL)		// the Particular letter is not present in the map
		{
			myNode->children[index] = getNode();
		}
 
		myNode = myNode->children[index];
	}
 
	myNode->isLeaf = true;
}
 
bool Search(struct TrieNode *root, string key)
{
	int len = key.length();
	int level = 0;
	struct TrieNode *myNode = root;
	char letter;
	int index;
 
	for(int i = 0;i <len;i++)
	{
		letter = key[i];
		index = CHAR_TO_INDEX(letter);
		if(myNode->children[index]==NULL)
		{
			return false;
		}
 
		myNode = myNode->children[index];
	}
 
	return (myNode && myNode->isLeaf); //mynodeis not null and is leaf -
}

bool is_final_node(struct TrieNode *root)
{
	if (root==NULL)
		return false; 
	for (int i =0; i<CHARACTERS; i++)
		if (root->children[i]!=NULL)
		return false; 
	return true; 
	
}
 
string LongestPrefixMatch(struct TrieNode *root, string word)
{
	int len = word.length();
	//cout <<"word \t"<<word<<"len \t"<<len; 
	string match, empty;
	char letter;
	int index; 
	bool found = false;
	for(int i= 0;i<len && root;i++)
	{
		letter = word[i];
		index = CHAR_TO_INDEX(letter);
		if(root->children[index])	// It has the current letter
		    	match.push_back(letter);
		root = root->children[index];
		if(root && root->isLeaf) // && is_final_node(root))
		 found = true;
	}
	if (found)
		return match;
	else
		return empty;
}
 
int main()
{
    string keys [] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their", "are", "area", "base", "basement", "len", "cater", 
                     "cat", "catercr", "erer"};
 
    string output[] = {"Not present in trie", "Present in trie"};
 
 
    struct TrieNode *root = getNode();
 
    // Construct trie
    int i;
    for (i = 0; i < ARRAY_SIZE(keys); i++)
    {
        Insert(root, keys[i]);
        //cout << "Key Inserted :: " << keys[i] << endl;
    }
    
    //cout<<output[int(Search(root, "the"))] ;
    //printf("%s --- %s\n", "these", output[Search(root, "these")].c_str() );
    //printf("%s --- %s\n", "their", output[Search(root, "their")].c_str() );
    //printf("%s --- %s\n", "caterer", output[Search(root, "caterer")].c_str() );
 
    
   
    string data[] = {"caterer", "child"};
    
     for(int i=0; i< ARRAY_SIZE(data); i++)
     {	string ans;
     	string res = LongestPrefixMatch(root, data[i]);
     	if (res.length()==0)
     		{
     		//cout <<"no";
     		ans = output[0]; 
     		cout << data[i]<< " :: " << ans.c_str()<< endl;}
     	else
     		{
     		//cout<<"yes";
     		ans = res;
     		cout << data[i]<< " :: " << ans.c_str()<< endl;}
     	
     }
 
    return 0;
}
