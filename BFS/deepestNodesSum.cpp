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
    int deepestLeavesSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> nodeKeeper;
        int maxLevelSum = 0;
        nodeKeeper.push({root, 0});
        int curLevel = 0;
        while(!nodeKeeper.empty()){
            auto curData = nodeKeeper.front();
            TreeNode* curNode = curData.first;
            int curDepth = curData.second;
            nodeKeeper.pop();
            if(curDepth == curLevel){
                maxLevelSum+=curNode->val;
            }
            else{
                curLevel = curDepth;
                maxLevelSum = curNode->val;
            }
            if(curNode->left != nullptr){
                nodeKeeper.push({curNode->left, curDepth+1});
            }
            if(curNode->right != nullptr){
                nodeKeeper.push({curNode->right, curDepth+1});
            }
        }
        return maxLevelSum;
    }
};