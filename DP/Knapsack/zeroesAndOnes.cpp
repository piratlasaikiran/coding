// https://leetcode.com/problems/ones-and-zeroes/discuss/1138695/JS-Python-Java-C%2B%2B-or-Easy-DP-Knapsack-Solution-w-Explanation
#include <bits/stdc++.h>
using namespace std;

class Solution_Memoization {
public:

    vector<vector<vector<int>>>dp;

    pair<int, int> getCurLen(string s){
        int n = s.size();
        int zeroes=0;
        int ones=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0')
                zeroes++;
            else
                ones++;
        }
        return {zeroes, ones};
    }

    int recursiveConsideration(vector<pair<int, int>> stringCharCounter, int remZeroes, int remOnes, int curIndex){
        if((remZeroes<=0 && remOnes<=0) || curIndex>=stringCharCounter.size())
            return 0;

        if(dp[curIndex][remZeroes][remOnes] != -1)
            return dp[curIndex][remZeroes][remOnes];

        if(stringCharCounter[curIndex].first > remZeroes || stringCharCounter[curIndex].second > remOnes)
            return dp[curIndex][remZeroes][remOnes] = recursiveConsideration(stringCharCounter, remZeroes, remOnes, curIndex+1);

        return dp[curIndex][remZeroes][remOnes] = max(1+recursiveConsideration(stringCharCounter, remZeroes-stringCharCounter[curIndex].first, remOnes-stringCharCounter[curIndex].second, curIndex+1), 
                    recursiveConsideration(stringCharCounter, remZeroes, remOnes, curIndex+1)
                    );
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int maxSubsetLen = 0;
        int stringsSize = strs.size();
        vector<pair<int, int>> stringCharCounter;
        for(int i=0; i<stringsSize; i++){
            stringCharCounter.push_back(getCurLen(strs[i]));
        }
        dp.resize(stringsSize, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        maxSubsetLen = recursiveConsideration(stringCharCounter, m, n, 0);
        return maxSubsetLen;
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1)); 
        for (string str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str)
                c == '0' ? zeros++ : ones++;
            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
        }
        return dp[m][n];
    }
};

int main(){
    Solution obj;
    vector<string> strs = {"0","0","1","1","1","0","1","0","0","1","1","0","1","0","1","0","1","0","0","1","0","1","0","0","1","1","1","0","1","1","0","0","1","1","1","0","1","0","0","0","1","0","1","0","0","1","0","0","1","1","1","1","1","0","0","1","0","1","0","1","1","0","0","0","1","1","1","1","1","1","0","1","1","1","0","0","1","1","0","0","1","1","0","1","0","0","1"};
    auto answer = obj.findMaxForm(strs,93, 91);
    cout << "Answer: " << answer << endl;
    return 0;
}