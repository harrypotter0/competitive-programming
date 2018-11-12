#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iterator>
#include<math.h>
#include<algorithm>

using namespace std;

struct trieNode {

trieNode *children[26];

bool endofword;

int weight;

};

trieNode *newNode() {

struct trieNode *node = new trieNode();

for (int i = 0; i < 26; ++i) {

node->children[i] = NULL;

}

node->endofword = false;
node->weight = -1;

return node;

}

void insert(trieNode *root, string s,int weight) {

struct trieNode *node = new trieNode();
node = root;

for (int i = 0; i < s.length(); ++i) {

int index = s[i] - 'a';

if (!node->children[index])
node->children[index] = newNode();

node = node->children[index];

if (node->weight < weight)
node->weight = weight;

}

node->endofword = true;

}

void search(trieNode *root, string s) {

struct trieNode *node = new trieNode();
node = root;

for (int i = 0; i < s.length(); ++i) {

int index = s[i] - 'a';

if (!node->children[index]) {
cout << -1 << endl;
return;
}

node = node->children[index];

}

cout << node->weight << endl;
return ;

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

struct trieNode *root = newNode();

int n, q;
cin >> n >> q;

for (int i = 0; i < n; i++) {
string s;
int weight;
cin >> s>>weight;
insert(root, s,weight);
}

while (q--) {

string s;
cin >> s;
search(root, s);

}

return 0;
}