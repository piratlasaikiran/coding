#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int EvaluateExpressionRecursive(string s, int i, int j, bool isTrue){
        if(i>j)
            return 0;

        if(i==j){
            if (isTrue){
                return s[i]=='T' ? 1 : 0;
            }
            else
                return s[i]=='F' ? 1 : 0;
        }
        int count=0;
        for(int k=i+1; k<j; k+=2){
            int lt = EvaluateExpressionRecursive(s, i, k-1, true);
            int lf = EvaluateExpressionRecursive(s, i, k-1, false);
            int rt = EvaluateExpressionRecursive(s, k+1, j, true);
            int rf = EvaluateExpressionRecursive(s, k+1, j, false);

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
        return count;
    }
};

int main(){
    Solution obj;
    string s = "T|T&F^T";
    auto answer = obj.EvaluateExpressionRecursive(s, 0, s.size()-1, true);
    cout << "Answer is: " << answer << endl;
    return 0;
}