#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> nodeCollector;
        nodeCollector.push({root, 0});
        while(!nodeCollector.empty()){
            auto curValues = nodeCollector.front();
            nodeCollector.pop();
            if(curValues.first != NULL && curValues.first->left != NULL)
                nodeCollector.push({curValues.first->left, curValues.second+1});
            if(curValues.first != NULL && curValues.first->right != NULL)
                nodeCollector.push({curValues.first->right, curValues.second+1});
            if(!nodeCollector.empty() && curValues.second == nodeCollector.front().second)
                curValues.first->next = nodeCollector.front().first;
        }
        return root;
    }
};