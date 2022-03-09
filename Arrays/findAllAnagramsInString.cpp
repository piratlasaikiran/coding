#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool areTheseWordsAnagrams(vector<int> sMapper, vector<int> pMapper){
        for(int i=0; i<26; i++){
            if(sMapper[i] != pMapper[i]){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        vector<int> answer = {};
        vector<int> sMapper(26, 0);
        vector<int> pMapper(26, 0);

        if(pSize > sSize){
            return answer;
        }
        for(int i=0; i<pSize; i++){
            sMapper[s[i]-'a']++;
            pMapper[p[i]-'a']++;
        }

        if(areTheseWordsAnagrams(sMapper, pMapper)){
            answer.push_back(0);
        }
        for(int i=pSize; i<sSize; i++){
            sMapper[s[i-pSize]-'a']--;
            sMapper[s[i]-'a']++;
            if(areTheseWordsAnagrams(sMapper, pMapper)){
                answer.push_back(i-pSize+1);
            }
        }
        return answer;
    }
};

int main(){
    string s = "cba";
    string p = "abc";
    Solution obj;
    auto answer = obj.findAnagrams(s, p);
    cout << "Answer: " ;
    for(auto i:answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}