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
    TreeNode* buildBinaryTree(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start>end)
            return NULL;

        static int postIndex = end;
        TreeNode* curNode = new TreeNode(postorder[postIndex--]);
        if(start==end)
            return curNode;
        int positionOfNodeInInorder = start;
        for(int i=start; i<=end; i++){
            if(inorder[i] == curNode->val){
                positionOfNodeInInorder = i;
                break;
            }
        }
        cout << "Built for: " << curNode->val << endl;
        curNode->right = buildBinaryTree(inorder, postorder, positionOfNodeInInorder+1, end);
        curNode->left = buildBinaryTree(inorder, postorder, start, positionOfNodeInInorder-1);
        return curNode;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return buildBinaryTree(preorder, inorder, 0, n-1);
        
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder {9,15,7,20,3};

    auto answer = obj.buildTree(inorder, postorder);
    obj.printInorder(answer);
    cout << endl;
    return 0;
}