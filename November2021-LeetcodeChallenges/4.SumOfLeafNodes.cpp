#include <bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
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

    int leftLeafNodesSum=0;

    void CalculateLeftLeafNodesSum(TreeNode* root, int position){
        if(!root)
            return;
        if(position==-1 && !root->left && !root->right)
            leftLeafNodesSum+=root->val;

        CalculateLeftLeafNodesSum(root->left, -1);
        CalculateLeftLeafNodesSum(root->right, 1);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        CalculateLeftLeafNodesSum(root->left, -1);
        CalculateLeftLeafNodesSum(root->right, 1);
        return leftLeafNodesSum;        
    }
};

    int main(){
    Solution obj;

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);


    auto answer = obj.sumOfLeftLeaves(root);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}