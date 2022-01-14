#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long answer = 0;
        int sign = 1;
        bool numberStart = false;
        for(auto i:s){
            if(i<='9' && i>='0'){
                numberStart = true;
                answer = answer*10 + i-'0';
                if(answer > INT_MAX){
                    break;
                }
            }
            else if(!numberStart && i==' '){
                continue;
            }
            else if(!numberStart && i=='+'){
                numberStart = true;
                continue;
            }
            else if(!numberStart && i=='-'){
                numberStart = true;
                sign = -1;
            }
            else{
                break;
            }
        }
        answer*=sign;
        if(answer > INT_MAX){
            return INT_MAX;
        }
        else if(answer < INT_MIN){
            return INT_MIN;
        }
        return (int)answer;

    }
};

int main(){
    Solution obj;
    auto answer = obj.myAtoi("-91283472332");
    cout << "Answer: " << answer << endl;
    cout << "INT MIN: " << INT_MIN << endl;
    return 0;
}