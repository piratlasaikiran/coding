#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false;
        unordered_set<string> subStringSet;
        
        for (int i = 0; i <= s.size()-k; i++)
            subStringSet.insert(s.substr(i, k));
        return subStringSet.size() == pow(2, k);
    }
};

int main(){
    Solution obj;
    string s = "1011110111001001101001110001100111101111010101011100111001110010010001000111010110101110000110101001011100100010100110011101011110001000100010101101011";
    int k=20;
    auto answer = obj.hasAllCodes(s, k);
    cout << "Answer: " << answer << endl;
    return 0;
}