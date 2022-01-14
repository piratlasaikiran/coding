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

    TreeNode* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start>end)
            return NULL;

        static int preIndex = 0;
        TreeNode* curNode = new TreeNode(preorder[preIndex++]);
        if(start==end)
            return curNode;
        auto it = find(inorder.begin(), inorder.end(), curNode->val);
        int positionOfNodeInPreorder = it - inorder.begin();
        cout << "Built for: " << inorder[start] << endl;
        curNode->left = buildBinaryTree(preorder, inorder, start, positionOfNodeInPreorder-1);
        curNode->right = buildBinaryTree(preorder, inorder, positionOfNodeInPreorder+1, end);
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
    vector<int> preorder = {-1};
    vector<int> inorder {-1};

    auto answer = obj.buildTree(preorder, inorder);
    obj.printInorder(answer);
    
    // cout << "Answer: " << answer << endl;
    return 0;
}