#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        for(int i=0; i<rows; i++){
            for(int j=i+1; j<columns; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns/2; j++){
                swap(matrix[i][j], matrix[i][columns-1-j]);
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    obj.rotate(matrix);
    cout << "Answer: " << endl;
    for(auto i:matrix){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;

}