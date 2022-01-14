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

    int findSuccessor(TreeNode* root){
        TreeNode *tmp = root;
        int successorValue = INT_MIN;
        tmp = tmp->right;
        if(!tmp)
            return successorValue;
        while(tmp->left)
            tmp = tmp->left;

        return tmp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;

        else if(root->val > key)
            root->left = deleteNode(root->left, key);

        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        else{
            if(!root->left && !root->right){
                delete(root);
                return nullptr;
            }
            else if(!root->left || !root->right){
                TreeNode *returnNode = root->left ? root->left : root->right;
                delete(root);
                return returnNode;
            }

            else{
                int successor = findSuccessor(root);
                root->val = successor;
                cout << "Successor: " << successor << endl;
                root->right = deleteNode(root->right, successor);
            }
        }

        return root;      
    }

    void printInorder(TreeNode* node)
    {
        if (node == NULL)
            return;
    
        /* first recur on left child */
        printInorder(node->left);
    
        /* then print the data of node */
        cout<<node->val<<" ";
    
        /* now recur on right child */
        printInorder(node->right);
    }
};

int main(){
    Solution obj;

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    // root->right = new TreeNode(6);
    // root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->right->right = new TreeNode(7);

    auto answer = obj.deleteNode(root, 2);
    obj.printInorder(answer);
    cout << endl;
    return 0;
}