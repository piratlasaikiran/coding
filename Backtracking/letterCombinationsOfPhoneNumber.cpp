#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string getCorrespondingLetters(char num){
        string alphabets = "";
        switch (num){
            case '2':
                alphabets = "abc";
                break;
            case '3':
                alphabets = "def";
                break;
            case '4':
                alphabets = "ghi";
                break;
            case '5':
                alphabets = "jkl";
                break;
            case '6':
                alphabets = "mno";
                break;
            case '7':
                alphabets = "pqrs";
                break;
            case '8':
                alphabets = "tuv";
                break;
            case '9':
                alphabets = "wxyz";
                break;
            default:
                break;
        }
        return alphabets;
    }

    void letterCombinationsHelper(vector<string>& answer, string digits, int curCharCount, string curCombination){
        int n = digits.size();
        if(curCharCount == n){
            answer.push_back(curCombination);
            return;
        }

        string possibilitiesWithCurChar = getCorrespondingLetters(digits[curCharCount]);
        int l = possibilitiesWithCurChar.size();
        for(int i=0; i<l; i++){
            curCombination.push_back(possibilitiesWithCurChar[i]);
            letterCombinationsHelper(answer, digits, curCharCount+1, curCombination);
            curCombination.pop_back();
        }
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        int n = digits.size();
        if(n==0)
            return {};
        letterCombinationsHelper(answer, digits, 0, "");
        return answer;   
    }
};

int main(){
    Solution obj;
    string digits = "23";
    auto answer = obj.letterCombinations(digits);
    for(auto i:answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}