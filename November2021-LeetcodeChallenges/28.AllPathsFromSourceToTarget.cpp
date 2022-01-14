#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void trace_all_paths(vector<vector<int>>& graph, vector<vector<int>> &all_paths, vector<int>& one_path, int next_step){

        if(next_step == graph.size() -1){
            all_paths.push_back(one_path);
            return;
        }

        for(int i=0; i<graph[next_step].size(); i++){
            one_path.push_back(graph[next_step][i]);
            trace_all_paths(graph, all_paths, one_path, graph[next_step][i]);
            one_path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> all_paths;
        vector<int> one_path = {0};
        int next_step=0;
        trace_all_paths(graph, all_paths, one_path, next_step);
        return all_paths;
    }
};