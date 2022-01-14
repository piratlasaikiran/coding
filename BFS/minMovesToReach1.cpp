#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> rr = {1, 0, -1, 0};
    vector<int> cc = {0, 1, 0, -1};

    bool isValidPositionInGrid(int i, int j, int rows, int columns){
        return ((i>=0) && (i<rows) && (j>=0) && (j<columns));
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> answer(rows, vector<int>(columns));
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        queue<vector<int>> neighbours;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                neighbours = {};
                fill(visited.begin(), visited.end(), vector<bool>(columns, false));
                neighbours.push({i, j, 0});
                visited[i][j] = true;
                while(!neighbours.empty()){
                    vector<int> positionInGrid = neighbours.front();
                    neighbours.pop();
                    int posX = positionInGrid[0];
                    int posY = positionInGrid[1];
                    int distanceReq = positionInGrid[2];
                    if(mat[posX][posY]== 0){
                        answer[i][j] = distanceReq;
                        break;
                    }
                    else{
                        for(int k=0; k<4; k++){
                            if(isValidPositionInGrid(posX+rr[k], posY+cc[k], rows, columns) && !visited[posX+rr[k]][posY+cc[k]]){
                                neighbours.push({posX+rr[k], posY+cc[k], distanceReq+1});
                                visited[posX][posY] = true;
                            }
                        }
                    }

                }

            }
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> mat = {{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{1,1,1},{0,0,0}};
    auto answer = obj.updateMatrix(mat);
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}