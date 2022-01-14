// https://www.youtube.com/watch?v=th4OnoGasMU till 19 Mins
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,bool> mem;
    unordered_set<string> myset;//dictionary
    bool partition(string s,int pos){
        if(pos==s.size())   return true;
        if(mem.count(pos))  return mem[pos];
        
        string t="";
        for(int i=pos;i<s.size();++i)
            if(myset.count(s.substr(pos,i-pos+1)) and partition(s,i+1))
                return mem[pos] = true;
        return mem[pos] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto str: wordDict)
            myset.insert(str);
        
        return partition(s,0);
    }
};

int main(){
    Solution obj;
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen"};
    auto answer = obj.wordBreak(s, wordDict);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}