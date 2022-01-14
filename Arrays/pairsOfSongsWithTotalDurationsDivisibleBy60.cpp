#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> moduloBy60(60, 0);
        for(auto i:time){
            moduloBy60[i%60]++;
        }
        int k=0;
        for(auto i:moduloBy60){
            cout << k << " " << i;
            k++;
            cout << endl;
        }
        cout << endl;
        int answer = 0;
        // if(moduloBy60[0] == 1)
        //     answer = 1;
        if(moduloBy60[0] > 1)
            answer = moduloBy60[0]*(moduloBy60[0]-1)/2;
        for(int i=1; i<30; i++){
            if(moduloBy60[i] !=0 && moduloBy60[60-i] != 0){
                cout << "Adding at index: " << i << endl;
                answer+=(max(moduloBy60[i], moduloBy60[60-i]));
            }
        }
        return answer+moduloBy60[30]/2;
    }
};

int main(){
    Solution obj;
    vector<int> time = {418,204,77,278,239,457,284,263,372,279,476,416,360,18};
    auto answer = obj.numPairsDivisibleBy60(time);
    cout << "Answer: " << answer << endl;
    return 0;
}