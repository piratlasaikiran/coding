#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int answer = 0;
        for(int i=0; i<n; i++){
            int curIndex = columnTitle[i]-'A'+1;
            answer+=(pow(26, n-1-i)*curIndex);
        }
        return answer;        
    }
};

int main(){
    string col = "AB";
    Solution obj;
    auto answer = obj.titleToNumber(col);
    cout << "Answer: " << answer << endl;
    return 0;
}