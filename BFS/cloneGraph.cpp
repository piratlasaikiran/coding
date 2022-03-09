#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    map<int, Node*> nodeMapper;

    Node* cloneHelper(Node* actual){
        if(!actual){
            return actual;
        }
        Node* copy = new Node(actual->val);
        nodeMapper[actual->val] = copy;
        int actualNodeNeighbourCount = actual->neighbors.size();
        
        for(int i=0; i<actualNodeNeighbourCount; i++){
            Node* tmpNode;
            if(nodeMapper.find(actual->neighbors[i]->val) != nodeMapper.end()){
                tmpNode = nodeMapper[actual->neighbors[i]->val];
            }
            else{
                tmpNode = cloneHelper(actual->neighbors[i]);
            }
            copy->neighbors.push_back(tmpNode);
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        return cloneHelper(node);
    }
};