#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int size = n;
        bool oneFound = false;
        for(int i=0; i<n; i++){
            if(nums[i] < 0)
                nums[i] = 0;
            else if(nums[i] == 1)
                oneFound = true;
        }

        if(!oneFound)
            return 1;

        for(int i=0; i<n; i++){
            int numIndex = abs(nums[i]);
            if(numIndex <= n && numIndex > 0){
                if(nums[numIndex-1] == 0){
                    nums[numIndex-1] = -1;
                }
                else if(nums[numIndex-1] > 0){
                    nums[numIndex-1] *= -1;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] > -1)
                return i+1;
        }

        return n+1;
    }
};

int main(){
    Solution obj;
    vector<int> grid = {3,4,0,2};

    auto answer = obj.firstMissingPositive(grid);
    cout << "Answer: " << answer << endl;
    return 0;
}
