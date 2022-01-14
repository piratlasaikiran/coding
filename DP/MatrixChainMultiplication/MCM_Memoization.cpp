#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dp{1000, vector<int>(1000, -1)};
    int MCM_Memoization(int arr[], int i, int j) {
        if(i>=j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans=INT_MAX;
        for(int k=i; k<=j-1; k++){
            ans = min(ans, MCM_Memoization(arr, i, k) + MCM_Memoization(arr, k+1, j) + arr[i-1]*arr[j]*arr[k]);
        }
        return dp[i][j] = ans;
    }
};

int main(){
    Solution obj;
    int arr[] = {1,2,3,4,3};
    int l = sizeof(arr)/sizeof(arr[0]);
    auto answer = obj.MCM_Memoization(arr, 1 , l-1);
    cout << "Answer is: " << answer << endl;
    return 0;
}