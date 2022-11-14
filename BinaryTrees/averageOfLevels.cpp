#include <iostream>
#include <vector>
#include <queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        queue<pair<TreeNode*, int>> bfsQueue;
        bfsQueue.push({root, 0});
        int curDepth = 0;
        int curSum = 0;
        int levelNodesCount = 0;

        while(!bfsQueue.empty()){
            auto curNode = bfsQueue.front();
            bfsQueue.pop();
            if(curNode.second == curDepth){
                curSum += curNode.first->val;
                levelNodesCount++;
            }
            else{
                answer.push_back(double(curSum)/levelNodesCount);
                curSum = curNode.first->val;
                curDepth++;
                levelNodesCount = 1;
            }
            if(curNode.first->left != nullptr){
                bfsQueue.push({curNode.first->left, curDepth+1});
            }
            if(curNode.first->right != nullptr){
                bfsQueue.push({curNode.first->right, curDepth+1});
            }
        }
        answer.push_back(double(curSum)/levelNodesCount);
        return answer;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution obj;

    auto answer = obj.averageOfLevels(root);
    cout << "Answer: " << endl;
    for(auto i:answer){
        cout << i << endl;
    }
    return 0;
}