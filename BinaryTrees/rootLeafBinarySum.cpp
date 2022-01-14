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

    int answer = 0;

    int getBase10Num(vector<int> binaryNums){
        int n = binaryNums.size();
        int base10Ans = 0;
        for(int i=0; i<n; i++){
            base10Ans+=(binaryNums[n-1-i]*pow(2, i));
        }
        return base10Ans;
    }

    void sumRootToLeafHelper(TreeNode* root, vector<int> binaryNums){
        if(!root){
            return;
        }
        binaryNums.push_back(root->val);
        if(!root->left && !root->right){
            
            answer += getBase10Num(binaryNums);
        }
        sumRootToLeafHelper(root->left, binaryNums);
        sumRootToLeafHelper(root->right, binaryNums);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<int> binaryNums;
        sumRootToLeafHelper(root, binaryNums);
        return answer;
    }
};