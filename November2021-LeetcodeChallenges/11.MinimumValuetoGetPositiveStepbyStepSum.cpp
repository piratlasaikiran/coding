#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        int startValue=1, i;
        bool foundStartValue=false;
        while(!foundStartValue){
            int tmp=startValue;
            cout << "StartValue: " << startValue << endl;
            for(i=0; i<n; i++){
                tmp+=nums[i];
                if(tmp<1){
                    startValue++;
                    break;
                }
            }
            if(i==n)
                foundStartValue=true;
        }
        return startValue;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {-3,2,-3,4,2};
    auto answer = obj.minStartValue(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}