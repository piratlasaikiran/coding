#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int answer = 0;
        while(n>0){
            if(n%2 == 1)
                answer++;
            n/=2;
        }
        return answer;
    }
};