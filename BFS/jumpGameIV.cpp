#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int lastIndex = arr.size()-1;
        map<int, vector<int>> sameValueIndicesMapper;
        for(int i=0; i <= lastIndex; i++){
            sameValueIndicesMapper[arr[i]].push_back(i);
        }
        queue<pair<int, int>> curPositionWithMoves;
        curPositionWithMoves.push({0, 0});
        vector<bool> visited(lastIndex+1, false);
        visited[0] = true;
        while(!curPositionWithMoves.empty()){
            int curIndex = curPositionWithMoves.front().first;
            int curMoves = curPositionWithMoves.front().second;
            curPositionWithMoves.pop();
            if(curIndex == lastIndex){
                return curMoves;
            }
            if(curIndex>0 && !visited[curIndex-1]){
                visited[curIndex-1] = true;
                curPositionWithMoves.push({curIndex-1, curMoves+1});
            }
            if(curIndex < lastIndex && !visited[curIndex+1]){
                visited[curIndex+1] = true;
                curPositionWithMoves.push({curIndex+1, curMoves+1});
            }
            for(auto i:sameValueIndicesMapper[arr[curIndex]]){
                if(!visited[i]){
                    curPositionWithMoves.push({i, curMoves+1});
                }
                sameValueIndicesMapper[arr[curIndex]].clear();
            }
        }
        return -1;

    }
};

int main(){
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    Solution obj;
    auto answer = obj.minJumps(arr);
    cout << "Answer: " << answer << endl;
    return 0;
}