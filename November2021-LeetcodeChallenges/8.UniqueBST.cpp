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
    
    int dp[20] = {0};
    int numTrees(int n) {
        if(n<=1)
            return 1;
        if(dp[n])
            return dp[n];
        for(int i=1; i<=n; i++){
            int left = i-1;
            int right = n-i;
            dp[n] += numTrees(left)*numTrees(right);
        }
        return dp[n];
    }
};

    int main(){
    Solution obj;

    
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(4);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);

    auto answer = obj.numTrees(3);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}

