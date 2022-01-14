#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xoredXY = x ^ y;
        unsigned int count = 0;
        while (xoredXY) {
            count += xoredXY & 1;
            xoredXY >>= 1;
        }
    return count;
    }
};

int main(){
    Solution obj;
    auto answer = obj.hammingDistance(1,4);
    cout << "Answer: " << answer << endl;
    return 0;
}