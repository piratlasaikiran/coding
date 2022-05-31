#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    void countStrings(string curString, int curIndex, int& answer, int n){
        cout << curString << endl;
        if(curString.size() == n){
            answer++;
            return;
        }
        for(int i=curIndex; i<5; i++){
            curString.push_back(vowels[i]);
            countStrings(curString, i, answer, n);
            curString.pop_back();
        }

    }

    int countVowelStrings(int n) {
        int answer = 0;
        countStrings("", 0, answer, n);
        return answer;
    }
};

int main(){
    Solution obj;
    int n = 3;
    auto answer = obj.countVowelStrings(n);
    cout << "Answer: " << answer << endl;
    return 0;
}