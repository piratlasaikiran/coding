#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<char> braces;
        for(int i=0; i<n; i++){
            if(s[i]==']'){
                if(!braces.empty()){
                    braces.pop();
                }
            }
            else{
                braces.push('[');
            }
        }
        return (braces.size()+1)/2;
    }
};

int main(){
    Solution obj;
    string s = "]]][[[";
    auto answer = obj.minSwaps(s);
    cout << "Answer: " << answer << endl;
    return 0;
}