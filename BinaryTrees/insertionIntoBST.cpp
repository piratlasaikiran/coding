#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* insertIntoBSTHelper(TreeNode* parent, TreeNode* root, int val){

        TreeNode* reqParentNode;
        if(!root){
            return parent;
        }
        if(root->val > val){
            reqParentNode = insertIntoBSTHelper(root, root->left, val);
        }
        else{
            reqParentNode = insertIntoBSTHelper(root, root->right, val);
        }
        return reqParentNode;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* bstRoot = new TreeNode(val);
            return bstRoot;
        }
        TreeNode* parent = insertIntoBSTHelper(nullptr, root, val);
        if(!parent->left && parent->val > val)
            parent->left = new TreeNode(val);
        else
            parent->right = new TreeNode(val);
        return root;
    }
};
