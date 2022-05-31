#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int quotient = 0;
        int temp = 0;
        bool sign = (dividend>=0) == (divisor>=0) ? true : false;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while(dividend >= divisor){
            temp = 0;
            while(dividend - (divisor << 1 << temp) >= 0){
                temp++;
            }
            quotient += (1<<temp);
            dividend-= (divisor<<temp);
        }
        return sign ? quotient : -quotient;
    }
};

int main(){
    Solution obj;
    int dividend = 7;
    int divisor = -3;
    auto answer = obj.divide(dividend, divisor);
    cout << "Answer: " << answer << endl;
    return 0;
}