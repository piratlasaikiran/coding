#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000][2];

class Solution{
    public:

    int EvaluateExpressionMemoization(string s, int i, int j, bool isTrue){
        if(i>j)
            return 0;

        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];

        if(i==j){
            if (isTrue){
                return dp[i][j][isTrue] = s[i]=='T' ? 1 : 0;
            }
            else
                return dp[i][j][isTrue] = s[i]=='F' ? 1 : 0;
        }
        int count=0;
        for(int k=i+1; k<j; k+=2){
            int lt = dp[i][j][isTrue] != -1 ? dp[i][j][isTrue] : EvaluateExpressionMemoization(s, i, k-1, true);
            int lf = dp[i][j][isTrue] != -1 ? dp[i][j][isTrue] : EvaluateExpressionMemoization(s, i, k-1, false);
            int rt = dp[i][j][isTrue] != -1 ? dp[i][j][isTrue] : EvaluateExpressionMemoization(s, k+1, j, true);
            int rf = dp[i][j][isTrue] != -1 ? dp[i][j][isTrue] : EvaluateExpressionMemoization(s, k+1, j, false);

            if(s[k] == '^'){
                if(isTrue)
                    count = count + lt*rf + lf*rt;
                else
                    count = count + lt*rt + lf*rf;
            }
            else if(s[k] == '|'){
                if(isTrue)
                    count = count + lt*rt + lf*rt + lt*rf;
                else
                    count = count + lf*rf;
            }
            else{
                if(isTrue)
                    count = count + lt*rt;
                else
                    count = count +  lf*rf + lf*rt + lt*rf;
            }
        }
        return dp[i][j][isTrue] = count;
    }
};

int main(){
    Solution obj;
    string s = "T|T&F^T";
    memset(dp, -1, sizeof(dp));
    auto answer = obj.EvaluateExpressionMemoization(s, 0, s.size()-1, true);
    cout << "Answer is: " << answer << endl;
    return 0;
}