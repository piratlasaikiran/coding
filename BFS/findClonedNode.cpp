#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> originalNodes;
        queue<TreeNode*> clonedNodes;
        originalNodes.push(original);
        clonedNodes.push(cloned);
        while(!originalNodes.empty()){
            TreeNode* curOrignalNode = originalNodes.front();
            TreeNode* curClonedNode = clonedNodes.front();
            originalNodes.pop();
            clonedNodes.pop();
            if(curOrignalNode == target){
                return curClonedNode;
            }
            if(curOrignalNode->left != NULL){
                originalNodes.push(curOrignalNode->left);
                clonedNodes.push(curClonedNode->left);
            }
            if(curOrignalNode->right != NULL){
                originalNodes.push(curOrignalNode->right);
                clonedNodes.push(curClonedNode->right);
            }
        }
        return NULL;
    }
};