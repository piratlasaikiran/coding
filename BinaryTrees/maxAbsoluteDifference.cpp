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

    int maxDifference = INT_MIN;

    void maxAncestorDiffHelper(TreeNode* root, int curMin, int curMax){
        int curAncestorMaxDiff = max(abs(curMax-root->val), abs(curMin-root->val));
        maxDifference = max(maxDifference, curAncestorMaxDiff);

        curMin = min(curMin, root->val);
        curMax = max(curMax, root->val);
        if(root->left)
            maxAncestorDiffHelper(root->left, curMin, curMax);
        if(root->right)
            maxAncestorDiffHelper(root->right, curMin, curMax);

    }

    int maxAncestorDiff(TreeNode* root) {
        int curMin = root->val, curMax = root->val;
        if(root->left)
            maxAncestorDiffHelper(root->left, curMin, curMax);
        if(root->right)
            maxAncestorDiffHelper(root->right, curMin, curMax);
        return maxDifference;        
    }
};

int main(){
    Solution obj;
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);

    auto answer = obj.maxAncestorDiff(root);
    cout << "Answer: " << answer << endl;
    return 0;
}