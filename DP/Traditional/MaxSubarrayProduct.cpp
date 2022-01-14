#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int MaxEndingHere=1;
        int MaxProduct = INT_MIN;
        int negativeProduct = 1;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                MaxEndingHere *= nums[i];
                negativeProduct = min(negativeProduct*nums[i], 1);
            }
            else if(nums[i]==0){
                MaxEndingHere = 1;
                negativeProduct = 1;
            }
            else{
                int tmp = MaxEndingHere;
                MaxEndingHere = max(negativeProduct*nums[i], 1);
                negativeProduct = tmp*nums[i];
            }
            if(MaxProduct < MaxEndingHere)
                MaxProduct = MaxEndingHere;
        }
        if(MaxProduct == 1 && find(nums.begin(), nums.end(), 1) == nums.end())
            return 0;

        return MaxProduct;
    }

    int checkThisSubProduct(vector<int> tmp){
        int positiveCount=0, negativeCount=0;
        for(auto i:tmp){
            if(i>0)
                positiveCount++;
            else
                negativeCount++;
        }
        if(negativeCount%2)
            return (positiveCount+negativeCount);
    }

    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int negativeCount=0, answer=0;
        for(int i=0; i<n;){
            int start=i;
            while(start<n && nums[start]==0)
                start++;
            int end=start;
            negativeCount=0;
            int startNegative=-1, endNegative=-1;
            while(end<n && nums[end] != 0){
                if(nums[end]<0){
                    negativeCount++;
                    if(startNegative==-1)
                        startNegative=end;
                    endNegative = end;
                }
                end++;
            }
            if(negativeCount%2==0)
                answer = max(answer, end-start);
            else{
                if(startNegative!=-1)
                    answer = max(answer, end-startNegative-1);
                if(endNegative!=-1)
                    answer = max(answer, endNegative-start);
            }
            i=end+1;
            
        }
        
        return answer;
    }
};

    int main(){
    Solution obj;
    vector<int> nums = {1, -2, -3, 4};
    auto answer = obj.getMaxLen(nums);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}