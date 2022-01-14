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
    void flatten(TreeNode* root) {
        if(!root)
            return;

        flatten(root->left); 
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* traverser = root->right;
        while(traverser->right){
            traverser = traverser->right;
        }
        traverser->right = tmp;
        flatten(tmp);
    }
};