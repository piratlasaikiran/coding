#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool firstUse = false;
        bool allCapital = false;
        firstUse = (word[0] >= 65 && word[0] <= 90);
        int n = word.size();
        for(int i=1; i<n; i++){
            if(word[i] >= 65 && word[i] <= 90){
                if(!firstUse){
                    return false;
                }
                if(i==1){
                    allCapital = true;
                }
                else{
                    if(!allCapital){
                        return false;
                    }
                }
            }
            else{
                if(allCapital){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution obj;
    string word = "Geeks";
    auto answer = obj.detectCapitalUse(word);
    cout << "Answer: " << answer << endl;
    return 0;
}