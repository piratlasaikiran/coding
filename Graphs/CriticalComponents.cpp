// Resource: https://www.youtube.com/watch?v=Rhxs4k6DyMM
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int time=0;

    void DFS(unordered_map<int, vector<int>> graph, vector<vector<int>>& bridges, vector<int> &low, vector<int> &discovery, vector<int> &parent, int u, int vertices){
        discovery[u] = time;
        low[u] = u;
        time++;

        for(int i:graph[u]){
            if(discovery[i] == -1){
                parent[i] = u;
                DFS(graph, bridges, low, discovery, parent, i, vertices);
                low[u] = min(low[u], low[i]);

                if(low[i] > discovery[u])
                    bridges.push_back({u, i});
            }
            else if(i != parent[u])
                low[u] = min(low[u], discovery[i]);

        }
    }

    void find_bridges(unordered_map<int, vector<int>> graph, vector<vector<int>>& bridges, int vertices){
        vector<int> low(vertices, -1);
        vector<int> discovery(vertices, -1);
        vector<int> parent(vertices, -1);

        for(int i=0; i<vertices; i++){
            if(discovery[i]==-1)
                DFS(graph, bridges, low, discovery, parent, i, vertices);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>> bridges;
        find_bridges(graph, bridges, n);
        return bridges;
    }

};

int main(){

    vector<vector<int>> connections;
    connections.push_back({1,0});
    connections.push_back({2,0});
    connections.push_back({3,2});
    connections.push_back({4,2});
    connections.push_back({4,3});
    connections.push_back({3,0});
    connections.push_back({4,0});

    Solution obj;
    auto answer = obj.criticalConnections(5, connections);
    for(auto i:answer){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    
}