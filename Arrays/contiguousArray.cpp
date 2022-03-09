#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int, int> sumIndexMapper;
        int sum = 0;
        sumIndexMapper[0] = -1;
        int curMaxContigousArrSize = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                sum+=(-1);
            }
            else{
                sum+=1;
            }
            if(sumIndexMapper.find(sum) != sumIndexMapper.end()){
                curMaxContigousArrSize = max(curMaxContigousArrSize, i-sumIndexMapper[sum]);
            }
            else{
                sumIndexMapper[sum] = i;
            }
        }
        return curMaxContigousArrSize;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,0,1};
    auto answer = obj.findMaxLength(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}