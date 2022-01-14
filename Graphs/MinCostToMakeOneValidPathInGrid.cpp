#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int xaxis[4] = {1, 0, -1, 0};
    int yaxis[4] = {0, 1, 0, -1};
    int dir[4] = {3, 1, 4, 2}; //directions mapping as per the x and y axis flow (order is important). 
	                           //[1][0] makes movement to below row without column change. So this will be 3 as per the given instruction in grid directions.

//checks if given position is out of bounds or not.
    bool is_this_valid_position(int i, int j, int &rows, int &columns){
        if(i >= 0 && i < rows && j >= 0 && j < columns)
            return true;
        return false;
    }

    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
		
	    //initialize a 2D vector with max_int. This will be used to compare costs in dijkstra algo.
        vector<vector<int>> dijkstra(rows, vector<int>(columns, INT_MAX));
        dijkstra[0][0] = 0;
        queue<tuple<int, int>> positions;
        tuple<int, int> traverser;
		//make start entry cost as 0
        positions.push(make_tuple(0, 0));
        while(!positions.empty()){
            traverser = positions.front();
            positions.pop();
            int r = get<0>(traverser);
            int c = get<1>(traverser);
            
            for(int i=0; i<4; i++){
                if(is_this_valid_position(r+xaxis[i], c+yaxis[i], rows, columns)){
                    if(dir[i] == grid[r][c]){
					//checking direction in grid, if matches then cost will be same as previous 
                        if(dijkstra[r+xaxis[i]][c+yaxis[i]] > dijkstra[r][c]){
                            dijkstra[r+xaxis[i]][c+yaxis[i]] = dijkstra[r][c];
                            positions.push(make_tuple(r+xaxis[i], c+yaxis[i]));
                        }
                    }
                    else{
                        if(dijkstra[r+xaxis[i]][c+yaxis[i]] > dijkstra[r][c]+1){
                            dijkstra[r+xaxis[i]][c+yaxis[i]] = dijkstra[r][c]+1;
                            positions.push(make_tuple(r+xaxis[i], c+yaxis[i]));
                        }
                    }
                    
                }
            }

        }
        return dijkstra[rows-1][columns-1];
        
    }
};