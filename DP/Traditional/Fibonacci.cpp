#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tri(int n) {
        vector<int> tribonacci(n, 0);
        tribonacci[0] = 0;
        tribonacci[1] = 1;
        tribonacci[2] = 1;

        for(int i=3; i<=n; i++){
            tribonacci[i] = tribonacci[i-1] + tribonacci[i-2] + tribonacci[i-3];
        }
        return tribonacci[n];
        
    }
};

int main(){
    Solution obj;
    auto answer = obj.tri(37);
    cout << "Answer is: " << answer << endl;
    return 0;
}