#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> tmpStorage  = {};
        int rows = mat.size();
        int columns = mat[0].size();

        for(int i=columns-1; i>=0; i--){
            tmpStorage = {};
            for(int c=i, r=0; c<columns && r<rows; c++, r++) tmpStorage.push_back({mat[r][c]});
            sort(tmpStorage.begin(), tmpStorage.end());
            for(int c=i, r=0; c<columns && r<rows; c++, r++) mat[r][c] = tmpStorage[r];
        }

        for(int i=1; i<rows; i++){
            tmpStorage = {};
            for(int c=0, r=i; c<columns && r<rows; c++, r++) tmpStorage.push_back(mat[r][c]);
            sort(tmpStorage.begin(), tmpStorage.end());
            for(int c=0, r=i; c<columns && r<rows; c++, r++) mat[r][c] = tmpStorage[c];
        }
        return mat;
    }
};

int main(){
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    Solution obj;
    auto answer = obj.diagonalSort(mat);
    cout << "Answer: " << endl;
    for(auto i:answer){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}