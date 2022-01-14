#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int travellingSalesMan(int mask, int curCity, int cities, int startCity, vector<vector<int>>& salesManDistances, vector<vector<int>>& dp){
        if(mask == (1<<cities)-1){
            return salesManDistances[curCity][startCity];
        }
        if(dp[mask][curCity] != -1){
            return dp[mask][curCity];
        }
        int minCost = INT_MAX;
        for(int i=0; i<cities; i++){
            if(mask&(1<<i)==0){
                int newMinDist = salesManDistances[curCity][i] + travellingSalesMan(mask|(1<<i), i, cities, startCity, salesManDistances, dp);
                minCost = min(minCost, newMinDist);
            }
        }
        return dp[mask][curCity] = minCost;
    }

    int getMinDistanceInGrid(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<vector<int>> salesManDistances(vertices, vector<int>(vertices, INT_MAX));
        vector<vector<int>> dp(pow(2, vertices), vector<int>(vertices, -1));
        for(int i=0; i<vertices; i++){
            vector<int> adj = graph[i];
            int adjSize = adj.size();
            for(int j=0; j<adjSize; j++){
                salesManDistances[i][adj[j]] = 1;
                salesManDistances[adj[j]][i] = 1;
            }
        }
        int visitedMask = (1<<vertices)-1;
        int answer = travellingSalesMan(1, 0, vertices, 0, salesManDistances, dp);
        return answer;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> graph = {{1,2,3},{0},{0},{0}};
    auto answer = obj.getMinDistanceInGrid(graph);
    cout << "Answer: " << answer << endl;
    return 0;
}