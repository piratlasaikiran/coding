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

int leftMax=0, rightMax=0;

void printTopView(TreeNode* root, int curLeft, int curRight){
    if(!root)
        return;

    printTopView(root->left, curLeft+1, curRight-1);

    if(curLeft > leftMax || curRight > rightMax){
        cout << root->val << " ";
        leftMax++;
    }

    else if(curRight > rightMax){
        cout << root->val << " ";
        rightMax++;
    }
    
    printTopView(root->right, curLeft-1, curRight+1);

    
}

    int main(){

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    int maxValue=0;
    printTopView(root, 1, 1);
    cout << endl;

    return 0;
}