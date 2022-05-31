#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows = 0;
    int columns = 0;
    vector<int> rowIndex = {1, 0, -1, 0};
    vector<int> colIndex = {0, 1, 0, -1};
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        columns = matrix[0].size();
        int maxPathLen = 0;
        dp.resize(rows, vector<int>(columns));
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                maxPathLen = max(maxPathLen, maxLengthFromPoint(matrix, i, j));
            }
        }
        return maxPathLen;
    }

    int maxLengthFromPoint(vector<vector<int>>& matrix, int curRow, int curCol){
        if(dp[curRow][curCol]){
            return dp[curRow][curCol];
        }
        dp[curRow][curCol] = 1;
        for(int k=0; k<4; k++){
            int newRow = curRow + rowIndex[k];
            int newCol = curCol + colIndex[k];
            if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= columns || matrix[newRow][newCol] <= matrix[curRow][curCol])
                continue;
            dp[curRow][curCol] = max(dp[curRow][curCol], 1+maxLengthFromPoint(matrix, newRow, newCol));
        }
        return dp[curRow][curCol];
    }
};

int main(){
    Solution obj;
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    auto answer = obj.longestIncreasingPath(matrix);
    cout << "Answer: " << answer << endl;
    return 0;
}