#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
class Solution{
    public:

    int EggDroppingMemoization(int floors, int eggs ){
        if(floors == 0 || floors ==1 || eggs ==0 || eggs == 1)
            return floors;
        if(dp[floors][eggs] != -1)
            return dp[floors][eggs];
        int mini = INT_MAX;
        for(int k=1; k<=floors; k++){
            mini = min(mini, 1+max(EggDroppingMemoization(k-1, eggs-1), EggDroppingMemoization(floors-k, eggs)));
        }   
        return dp[floors][eggs] = mini;
    }
};

int main(){
    Solution obj;
    int eggs = 2;
    int floors = 4;
    memset(dp, -1, sizeof(dp));
    auto answer = obj.EggDroppingMemoization(floors, eggs);
    cout << "Answer is: " << answer << endl;
    return 0;
}