#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int steps=0;
        int rowCoins=1;
        while(n>0){
            if(n>=rowCoins){
                n-=rowCoins;
                rowCoins++;
                steps++;
            }
            else
                break;
        }
        return steps;
    }
};

    int main(){
    Solution obj;
    auto answer = obj.arrangeCoins(5);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}

