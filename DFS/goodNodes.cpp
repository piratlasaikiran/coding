#include <iostream>
#include <vector>
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

    void goodNodeFinder(TreeNode* node, int& goodNodeCount, int curMax){
        if(node->val >= curMax)
            goodNodeCount++;

        if(node->left != nullptr)
            goodNodeFinder(node->left, goodNodeCount, max(curMax, node->val));
        if(node->right != nullptr)
            goodNodeFinder(node->right, goodNodeCount, max(curMax, node->val));        
    }

    int goodNodes(TreeNode* root) {
        int goodNodeCount = 0;
        goodNodeFinder(root, goodNodeCount, root->val);
        return goodNodeCount;
    }
};