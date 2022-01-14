#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            answer ^= nums[i];
        }
        return answer;
    }
};

int main(){
    Solution obj;
    vector<int> grid = {1,1,2,3,3,4,4,8,8};

    auto answer = obj.singleNonDuplicate(grid);
    cout << "Answer: " << answer << endl;
    return 0;
}