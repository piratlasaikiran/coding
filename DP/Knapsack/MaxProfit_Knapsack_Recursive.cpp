#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int recursive(vector<int>& values, vector<int>& weights, int weight, int n, int start)
    {
        if(start==n || weight==0)
            return 0;
        if(weights[start] <= weight){
            return max((values[start] + recursive(values, weights, weight-weights[start], n, start+1)), recursive(values, weights, weight, n, start+1));
        }
        else{
            return recursive(values, weights, weight, n, start+1);
        }
    }
    int maxProfit(vector<int>& values, vector<int>& weights, int weight, int n) 
    {
        return recursive(values, weights, weight, n, 0);

    }
};
int main(){
    Solution obj;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int weight = 50;
    int n = values.size();
    auto answer = obj.maxProfit(values, weights, weight, n);
    cout << "Answer is: " << answer << endl;
    
    return 0;
}