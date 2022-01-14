#include <bits/stdc++.h>
using namespace std;

class Solution{

    vector<vector<int>> floydWarshall(vector<vector<int>> edges, int vertices){
        vector<vector<int>> allPairShortestData(vertices, vector<int>(vertices, INT_MAX));
        int n = edges.size();
        for(int i=0; i<n; i++){
            int start = edges[i][0];
            int end = edges[i][1];
            int weight = edges[i][2];
            allPairShortestData[start][end] = weight;
            allPairShortestData[end][start] = weight;
        }
        for(int i=0; i<vertices; i++){
            allPairShortestData[i][i] = 0;
        }

        for(int k=0; k<vertices; k++){
            for(int i=0; i<vertices; i++){
                for(int j=0; j<vertices; j++){
                    if(allPairShortestData[i][k] == INT_MAX || allPairShortestData[k][j] == INT_MAX){
                        continue;
                    }
                    else if(allPairShortestData[i][k] + allPairShortestData[k][j] < allPairShortestData[i][j]){
                        allPairShortestData[i][j] = allPairShortestData[i][k] + allPairShortestData[k][j];
                    }
                }
            }
        }
    }

};