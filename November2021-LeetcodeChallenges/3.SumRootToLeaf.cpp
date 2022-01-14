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

    int RootToLeafSum=0;

    void CalculateSumOfPaths(TreeNode* root, int num){
        if(!root)
            return;  
        num = num*10 + root->val;
        if(!root->left && !root->right)
            RootToLeafSum+=num;
        CalculateSumOfPaths(root->left, num);
        CalculateSumOfPaths(root->right, num);
    }

    int sumNumbers(TreeNode* root) {
        CalculateSumOfPaths(root, 0);
        return RootToLeafSum;
    }
};

    int main(){
    Solution obj;

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);

    auto answer = obj.sumNumbers(root);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}