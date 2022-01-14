#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<bool> visited;

    bool canReachHelper(vector<int>& arr, int start) {
        if(visited[start])
            return false;
        if(arr[start] == 0)
            return true;
        visited[start] = true;
        int rightJump = start + arr[start];
        int leftJump = start - arr[start];

        bool rightJumpPossibility = false, leftJumpPossibility = false;
        if(rightJump>=0 && rightJump<arr.size())
            rightJumpPossibility = canReach(arr, rightJump);

        if(leftJump>=0 && leftJump<arr.size())
            leftJumpPossibility = canReach(arr, leftJump);

        return (leftJumpPossibility || rightJumpPossibility);
        
    }

    bool canReach(vector<int>& arr, int start){
        int n = arr.size();
        visited.resize(n, false);
        return canReachHelper(arr, start);
    }
};

int main(){
    Solution obj;
    vector<int> arr = {3,0,2,1,2};
    auto answer = obj.canReach(arr, 2);
    cout << "Answer: " << answer << endl;
    return 0;
}