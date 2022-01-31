#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> getNextMinIndex(vector<int>& heights){
        int n = heights.size();
        vector<int> nextMinIndices(n, n);
        stack<int> nextMinStack;
        for(int i=n-1; i>=0; i--){
            while(!nextMinStack.empty() && heights[nextMinStack.top()] >= heights[i]){
                nextMinStack.pop();
            }
            if(!nextMinStack.empty()){
                nextMinIndices[i] = nextMinStack.top();
            }
            nextMinStack.push(i);
        }
        return nextMinIndices;
    }

    vector<int> getPrevMinIndex(vector<int>& heights){
        int n = heights.size();
        vector<int> prevMinIndices(n, -1);
        stack<int> prevMinStack;
        for(int i=0; i<n; i++){
            while(!prevMinStack.empty() && heights[prevMinStack.top()] >= heights[i]){
                prevMinStack.pop();
            }
            if(!prevMinStack.empty()){
                prevMinIndices[i] = prevMinStack.top();
            }
            prevMinStack.push(i);
        }
        return prevMinIndices;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextMinIndices = getNextMinIndex(heights);
        vector<int> prevMinIndices = getPrevMinIndex(heights);
        int n = heights.size();
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++){
            int curMaxArea = (nextMinIndices[i]-prevMinIndices[i]-1)*heights[i];
            maxArea = max(maxArea, curMaxArea);
        }
        return maxArea;
    }
};

int main(){
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    auto answer = obj.largestRectangleArea(heights);
    cout << "Answer: " << answer << endl;
    return 0;
}