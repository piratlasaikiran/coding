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
        queue<pair<Node*, int>> nodesLevelOrder;
        nodesLevelOrder.push({root, 0});
        while(!nodesLevelOrder.empty()){
            auto pairNodeDepth = nodesLevelOrder.front();
            nodesLevelOrder.pop();
            Node* curNode = pairNodeDepth.first;
            int curDepth = pairNodeDepth.second;
            if(curNode->left){
                nodesLevelOrder.push({curNode->left, curDepth+1});
            }
            if(curNode->right){
                nodesLevelOrder.push({curNode->right, curDepth+1});
            }
            if(!nodesLevelOrder.empty() && curDepth == nodesLevelOrder.front().second){
                curNode->next = nodesLevelOrder.front().first;
            }
        }
        return root;
    }
};