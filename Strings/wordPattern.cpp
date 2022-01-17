#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        swap(pattern, s);
        char *patternString = (char *)pattern.c_str();
        char *token = strtok(patternString, " ");
        vector<string> tokenizedPattern;
        while(token != NULL){
            tokenizedPattern.push_back(token);
            token = strtok(NULL, " ");
        }
        if(tokenizedPattern.size() != s.size()){
            return false;
        }
        int n = s.size();
        map<char, string> fullMatchPattern;
        set<string> usedPatterns;
        for(int i=0; i<n; i++){
            if(fullMatchPattern.find(s[i]) == fullMatchPattern.end()){
                if(usedPatterns.find(tokenizedPattern[i]) == usedPatterns.end()){
                    fullMatchPattern[s[i]] = tokenizedPattern[i];
                    usedPatterns.insert(tokenizedPattern[i]);
                }
                else{
                    return false;
                }
            }
            else{
                string foundPattern = fullMatchPattern[s[i]];
                string curPattern = tokenizedPattern[i];
                if(foundPattern != curPattern){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution obj;
    string pattern = "dog cat cat dog";
    string s = "abba";
    auto answer = obj.wordPattern(s, pattern);
    cout << "Answer: " << answer << endl;
    return 0;
}