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

    map<int, pair<int,int>> bottomNodes;

    void bottomView(TreeNode* root, int xCord, int yCord){
        if(!root)
            return;
        if(bottomNodes.find(xCord) == bottomNodes.end())
            bottomNodes[xCord] = {root->val, yCord};

        else{
            if(bottomNodes[xCord].second <= yCord){
                bottomNodes[xCord].first = root->val;
                bottomNodes[yCord].second = yCord;
            }
        }
        bottomView(root->left, xCord-1, yCord+1);
        bottomView(root->right, xCord+1, yCord+1);
    }
        
};

    int main(){

    TreeNode * root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    int maxValue=0;
    Solution obj;
    obj.bottomView(root, 0, 0);
    auto answer = obj.bottomNodes;

    map<int, pair<int,int>>::iterator it;
    for(auto i:answer){
            cout << i.second.first << " ";
    }

    cout << endl;

    return 0;
}