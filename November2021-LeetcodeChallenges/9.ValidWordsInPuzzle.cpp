#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        map<char, vector<int>> CharMap;
        for(int i=0; i<26; i++){
            CharMap.insert({'a'+i,vector<int>()});
        }

        for(auto word:words){
            int mask=0;
            for(auto ch:word){
                int bit = ch - 'a';
                mask = mask | (1<<bit);
            }
            vector<bool> placed(26, false);
            for(auto ch:word){
                if(!placed[ch-'a']){
                    CharMap[ch].push_back(mask);
                    placed[ch-'a'] = true;
                }
            }
        }
        
        vector<int> answer;
        for(auto puzzle:puzzles){
            int mask=0;
            for(auto ch:puzzle){
                int bit = ch - 'a';
                mask = mask | (1<<bit);
            }
            char fch = puzzle[0];
            vector<int> charBitMask = CharMap[fch];
            int validword=0;
            for(auto bitMaskedWord:charBitMask){
                if(bitMaskedWord == (bitMaskedWord & mask))
                    validword++;
            }
            answer.push_back(validword);
        }
        return answer;

    }
};


    int main(){
    Solution obj;
    vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    auto answer = obj.findNumOfValidWords(words, puzzles);

    // cout << "Answer: " << answer << endl;

    for(auto j:answer)
        cout << j << " ";
    cout << endl;

    return 0;
}

