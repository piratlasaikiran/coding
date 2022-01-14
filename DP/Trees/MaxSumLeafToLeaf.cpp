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

    int calculateMaxSumPath(TreeNode* root, int& sum){
        if(!root)
            return 0;

        
        int left_sum = calculateMaxSumPath(root->left, sum);
        int right_sum = calculateMaxSumPath(root->right, sum);
        int temp = max(left_sum, right_sum)+root->val;
        int ans = max(temp, left_sum+right_sum+root->val);

        sum = max(ans, sum);
        return ans;

    }

    int maxPathSum(TreeNode* root) {
        int sum=0;
        calculateMaxSumPath(root, sum);
        return sum;
    }
};

int main(){

    Solution obj;

    TreeNode *root = new TreeNode(-15);
    root->left = new TreeNode(5);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(-8);
    root->left->right = new TreeNode(1);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->right->right= new TreeNode(0);
    root->right->right->right->left= new TreeNode(4);
    root->right->right->right->right= new TreeNode(-1);
    root->right->right->right->right->left= new TreeNode(10);

    auto answer = obj.maxPathSum(root);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}