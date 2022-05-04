#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int longestArrayWithPositiveSum(vector<int>& nums){
        
    }

    int longestWPI(vector<int>& hours) {
        vector<int> binaryDays;
        int n = hours.size();
        for(int i=0; i<n; i++){
            if(hours[i] > 8){
                binaryDays.push_back(1);
            }
            else{
                binaryDays.push_back(-1);
            }
        }
        int answer = longestArrayWithPositiveSum(binaryDays);
        return answer;
    }
};

int main(){
    vector<int> hours = {9,9,6,0,6,6,9};
    Solution obj;
    auto answer = obj.longestWPI(hours);
    cout << "Answer: " << answer << endl;
    return 0;
}