#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
public:
    vector<string> combinations;
    int position;
    void util(string s, int n, int pos, int lengthRem, string tmpComb){
        if(lengthRem==0){
            combinations.push_back(tmpComb);
            return;
        }
        if(pos>=n){
            return;
        }
        tmpComb+=s[pos];
        util(s, n, pos+1, lengthRem-1, tmpComb);
        tmpComb.pop_back();
        util(s, n, pos+1, lengthRem, tmpComb);
    }
    CombinationIterator(string characters, int combinationLength) {
        util(characters, characters.size(), 0, combinationLength, "");
        position=0;
    }
    
    string next() {
        return combinations[position++];
    }
    
    bool hasNext() {
        return position < combinations.size();
    }
};