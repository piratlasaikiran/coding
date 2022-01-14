#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int index = abs(nums[i])-1;
            nums[index] = nums[index] > 0 ? -nums[index] : nums[index];
        }
        vector<int> answer;
        for(int i=0; i<n; i++){
            if(nums[i]>0)
                answer.push_back(i+1);
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<int> grid = {4,3,2,7,8,2,3,1};

    auto answer = obj.findDisappearedNumbers(grid);
    for(auto i:answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}