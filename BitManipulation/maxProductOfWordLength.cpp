#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int answer=0;
        vector<int> bitMask(n);
        for(int i=0; i<n; i++){
            for(auto ch:words[i]){
                bitMask[i] |= 1 << (ch-'a');
            }
            for(int j=0; j<i; j++){
                if((bitMask[i] & bitMask[j]) == 0){
                    answer = max(answer, int(words[i].size()*words[j].size()));
                }
            }
        }
        return answer;
    }
};