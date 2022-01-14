#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> getNextMin(vector<int> nums){
        stack<int> minValue;
        int n = nums.size();
        vector<int> nextMinimumValues(n, n);
        for(int i=n-1; i>=0; i--){
            if(!minValue.empty()){
                while(!minValue.empty() && nums[minValue.top()] >= nums[i]){
                    minValue.pop();
                }
                if(!minValue.empty())
                    nextMinimumValues[i] = minValue.top();
            }
            minValue.push(i);

        }
        return nextMinimumValues;
    }

    vector<int> getPrevMin(vector<int> nums){
        stack<int> minValue;
        int n = nums.size();
        vector<int> prevMinimumValues(n, -1);
        for(int i=0; i<n; i++){
            if(!minValue.empty()){
                while(!minValue.empty() && nums[minValue.top()] >= nums[i]){
                    minValue.pop();
                }
                if(!minValue.empty())
                    prevMinimumValues[i] = minValue.top();
            }
            minValue.push(i);

        }
        return prevMinimumValues;
    }

    int maxAreaHistogram(vector<int> groundLevel){
        int n = groundLevel.size();
        vector<int> previousMinimums = getPrevMin(groundLevel);
        vector<int> nextMinimums = getNextMin(groundLevel);
        int answer=0;
        for(int i=0; i<n; i++){
            int curAnswer = (nextMinimums[i]-previousMinimums[i]-1)*groundLevel[i];
            answer = max(answer, curAnswer);
        }
        return answer;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows==0)
            return 0;
        int columns = matrix[0].size();
        vector<int> groundLevel(columns, 0);
        int answer=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(matrix[i][j] == '0')
                    groundLevel[j] = 0;
                else
                    groundLevel[j] = groundLevel[j] + 1;
            }
            int curAnswer = maxAreaHistogram(groundLevel);
            answer = max(answer, curAnswer);
        }        
        return answer;       
    }
};

int main(){
    Solution obj;
    vector<vector<char>> account = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    auto answer = obj.maximalRectangle(account);
    // auto answer = obj.getPrevMin({1, 1});
    // for(auto i:answer)
    //     cout << i << " ";
    // cout << endl;
    cout << "Answer: " << answer << endl;
    return 0;
}