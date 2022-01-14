#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int destinationReached = (1<<n)-1;
        vector<vector<int>>dp (n, vector<int>(1<<n, -1));
        queue<pair<int, int>> visitedStates;
        

        for(int i=0; i<n; i++) {
            visitedStates.push({i,1<<i});
            dp[i][1<<i]=0;
        }
        
        while(!visitedStates.empty()){
            pair<int, int> vertexState = visitedStates.front();
            visitedStates.pop();
            int curNode = vertexState.first;
            int curVisState = vertexState.second;
            if(curVisState==destinationReached){
                return dp[curNode][curVisState];
            }
            
            for(auto i: graph[curNode]){
                int k=curVisState|(1<<i);
                if(k==destinationReached) 
                    return dp[curNode][curVisState]+1;
                if(dp[i][k]==-1){
                    dp[i][k]=dp[curNode][curVisState]+1;
                    visitedStates.push({i,k});
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> graph = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    auto answer = obj.shortestPathLength(graph);
    cout << "Answer: " << answer << endl;
    return 0;
}