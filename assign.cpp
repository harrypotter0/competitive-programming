
#include<bits/stdc++.h>
using namespace std;

TreeNode* mirror(struct TreeNode* node) 
{ 
    if (node==NULL) 
        return node; 
    else
    { 
        struct TreeNode* temp; 

        mirror(node->left); 
        mirror(node->right); 

        temp	 = node->left; 
        node->left = node->right; 
        node->right = temp; 
    } 
} 

void inOrder(struct TreeNode* node) 
{ 
    if (node == NULL) 
        return; 

    inOrder(node->left); 
    printf("%d ", node->val); 
    inOrder(node->right); 
} 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        return mirror(root);     
    }
};

// int main() 
// { 
    
//     printf("Inorder traversal of the constructed"
//             " tree is \n"); 
//     inOrder(root); 

//     mirror(root); 

//     printf("\nInorder traversal of the mirror tree"
//             " is \n"); 
//     inOrder(root); 

//     return 0; 
// } 

// void trimLeftTrailingSpaces(string &input) {
//     input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//         return !isspace(ch);
//     }));
// }

// void trimRightTrailingSpaces(string &input) {
//     input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//         return !isspace(ch);
//     }).base(), input.end());
// }

// TreeNode* stringToTreeNode(string input) {
//     trimLeftTrailingSpaces(input);
//     trimRightTrailingSpaces(input);
//     input = input.substr(1, input.length() - 2);
//     if (!input.size()) {
//         return nullptr;
//     }

//     string item;
//     stringstream ss;
//     ss.str(input);

//     getline(ss, item, ',');
//     TreeNode* root = new TreeNode(stoi(item));
//     queue<TreeNode*> nodeQueue;
//     nodeQueue.push(root);

//     while (true) {
//         TreeNode* node = nodeQueue.front();
//         nodeQueue.pop();

//         if (!getline(ss, item, ',')) {
//             break;
//         }

//         trimLeftTrailingSpaces(item);
//         if (item != "null") {
//             int leftNumber = stoi(item);
//             node->left = new TreeNode(leftNumber);
//             nodeQueue.push(node->left);
//         }

//         if (!getline(ss, item, ',')) {
//             break;
//         }

//         trimLeftTrailingSpaces(item);
//         if (item != "null") {
//             int rightNumber = stoi(item);
//             node->right = new TreeNode(rightNumber);
//             nodeQueue.push(node->right);
//         }
//     }
//     return root;
// }

// string treeNodeToString(TreeNode* root) {
//     if (root == nullptr) {
//       return "[]";
//     }

//     string output = "";
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()) {
//         TreeNode* node = q.front();
//         q.pop();

//         if (node == nullptr) {
//           output += "null, ";
//           continue;
//         }

//         output += to_string(node->val) + ", ";
//         q.push(node->left);
//         q.push(node->right);
//     }
//     return "[" + output.substr(0, output.length() - 2) + "]";
// }

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         TreeNode* root = stringToTreeNode(line);
        
//         TreeNode* ret = Solution().mirror(root);

//         string out = treeNodeToString(ret);
//         cout << out << endl;
//     }
//     return 0;
// }
