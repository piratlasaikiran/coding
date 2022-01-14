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

    map<int, map<int,set<int>>> verticalOrderMap;

    void collectNodesVertical(TreeNode* root, int xCord, int yCord){
        if(!root)
            return;
        verticalOrderMap[xCord][yCord].insert(root->val);
        collectNodesVertical(root->left, xCord-1, yCord+1);
        collectNodesVertical(root->right, xCord+1, yCord+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        collectNodesVertical(root, 0, 0);
        vector<vector<int>> answer;
        for(auto i:verticalOrderMap){
            answer.push_back(vector<int>());
            for(auto j:i.second){
                for(auto k:j.second)
                    answer.back().push_back(k);
            }
        }
        return answer;        
    }
};

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
    Solution obj;
    auto answer = obj.verticalTraversal(root);
    cout << endl;

    return 0;
}