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

    int h=0;
    int Calculatediameter(TreeNode* root, int &d) {
        if(!root)
            return 0;
        
        int rightd,leftd,height,ans;
        leftd = Calculatediameter(root->left, d);
        rightd = Calculatediameter(root->right, d);
        height = max(leftd, rightd) + 1;
        ans = max(height, leftd+rightd+1);

        d = max(ans, height);  
        return height;
    }

    int diameterOfBinaryTree(TreeNode *root){
        int d=INT_MIN;
        Calculatediameter(root, d);
        return d-1;
    }
};

int main(){

    Solution obj;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(3);
    // root->right->right->right = new TreeNode(4);

    auto answer = obj.diameterOfBinaryTree(root);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}