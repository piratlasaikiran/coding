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

void printRightView(TreeNode* root, int curValue, int* maxValue){
    if(!root)
        return;
    if(curValue > *maxValue){
        cout << root->val << " ";
        *maxValue+=1;
    }
    printRightView(root->right, curValue+1, maxValue);
    printRightView(root->left, curValue+1, maxValue);

    
}

    int main(){

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(9);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    int maxValue=0;
    printRightView(root, 1, &maxValue);
    cout << endl;

    return 0;
}