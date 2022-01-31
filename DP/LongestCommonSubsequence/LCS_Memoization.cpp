#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int LCSMemoize_helper(string s1, string s2, int l1, int l2, vector<vector<int>> dp){
        if(l1==0 || l2==0)
            return 0;
        if(dp[l1][l2] != -1)
            return dp[l1][l2];
        if(s1[l1-1]==s2[l2-1])
            return dp[l1-1][l2-1] = 1+LCSMemoize_helper(s1, s2, l1-1, l2-1, dp);
        else
            return dp[l1-1][l2-1] = max(LCSMemoize_helper(s1, s2, l1-1, l2, dp), LCSMemoize_helper(s1, s2, l1, l2-1, dp));
    }

    int LCSMemoize(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return LCSMemoize_helper(s1, s2, l1, l2, dp);        
    }
};

int main(){
    Solution obj;
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    auto answer = obj.LCSMemoize(s1, s2);
    cout << "Answer is: " << answer << endl;
    return 0;
}