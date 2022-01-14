#include <bits/stdc++.h>
using namespace std;

vector<int> dsuf;

int find(int v){
    if(dsuf[v] == -1)
        return v;
    return find(dsuf[v]);
}

void union_op(int fromP, int toP){
    fromP = find(fromP);
    toP = find(toP);
    dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int,int>>& edge_list){
    for(auto p:edge_list){
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP)
            return true;
        
        union_op(fromP, toP);
    }
    return false; 
}

int main(){
    int E=4;
    int V=4;

    dsuf.resize(V, -1);
    vector<pair<int,int>> edge_list;
    edge_list.push_back({0,1});
    edge_list.push_back({0,2});
    edge_list.push_back({2,3});
    edge_list.push_back({1,3});

    if(isCyclic(edge_list))
        cout << "Contains Cycle\n";
    else
        cout << "No Cycle\n";

    return 0;

}