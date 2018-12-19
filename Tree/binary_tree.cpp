#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node createnode(int c) {
    node ptr;
    ptr=(node)malloc(sizeof(struct Node));
    ptr->key=c;
    ptr->left=NULL;
    ptr->right=NULL;
    return(ptr);
}
node temp=NULL;

void search(int val,node p) {
    if(p==NULL) 
    return;
    else {
        search(val,p->left);
        if(p->key==val)
        temp=p;
        search(val,p->right);
    } 
}

/*
void printInorder(struct Node* node)
{
if (node == NULL)
return;

// printInorder(node->left);


// printf("%d ", node->key);


// printInorder(node->right);
} 
*/

int mirror(node tree1,node tree2,int val,int x) 
{
    if((tree1==NULL||tree2==NULL))
    {
        return -1;
    }
    if(tree1->key==val) 
    return(tree2->key);
    else if(tree2->key==val)
    return tree1->key;
    
    int ans=(mirror(tree1->left,tree2->right,val,0));
    if(ans!=-1)
    return ans;
    
    return(mirror(tree1->right,tree2->left,val,1));

}

int main()
{
    char ch;
    int n,q,p,c,target,mi;
    cin>>n>>q;
    cin>>p>>c>>ch;
    node tree=createnode(p);
    if(ch=='L')
    tree->left=createnode(c);
    else 
    tree->right=createnode(c);
    n=n-2;
    while(n--) {
        cin>>p>>c>>ch;
        search(p,tree);
        
        if(ch=='L') 
        temp->left=createnode(c);
        else
        temp->right=createnode(c);
        temp=NULL;
    }
    
    //printInorder(tree);
    
    cout<<endl;
    while(q--) {
        cin>>target;
        mi=mirror(tree,tree,target,1);
        cout<<mi<<endl;
    }
    return 0;
}