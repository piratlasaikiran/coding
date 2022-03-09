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

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> treeIndexer;
        long maxWidth = 0;
        treeIndexer.push({root, 0});
        while(!treeIndexer.empty()){
            int curLevelSize = treeIndexer.size();
            long leftMostIndex = treeIndexer.front().second;
            long rightMostIndex = treeIndexer.front().second;
            while(curLevelSize-- > 0){
                auto nodeData = treeIndexer.front();
                treeIndexer.pop();
                rightMostIndex = nodeData.second;
                if(nodeData.first->left != nullptr){
                    treeIndexer.push({nodeData.first->left, 2*rightMostIndex+1});
                }
                if(nodeData.first->right != nullptr){
                    treeIndexer.push({nodeData.first->right, 2*rightMostIndex+2});
                }
            }
            maxWidth = max(maxWidth, rightMostIndex-leftMostIndex+1);
        }
        return (int)maxWidth;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution obj;
    auto answer = obj.widthOfBinaryTree(root);
    cout << "Answer: " << answer << endl;
    return 0;
}