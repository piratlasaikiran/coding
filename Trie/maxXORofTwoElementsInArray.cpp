#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct TrieNode{
        TrieNode *children[2];
    };

    void insert(TrieNode* root, int num){
        TrieNode* curNode = root;
        for(int i=31; i>=0; i--){
            int mask = 1<<i;
            int bit = (mask & num) ? 1 : 0;
            if(curNode->children[bit] == nullptr){
                curNode->children[bit] = new TrieNode();
            }
            curNode = curNode->children[bit];
        }
    }

    int search(TrieNode* root, int num){
        int curMaxVal = 0;
        TrieNode* curNode = root;
        for(int i=31; i>=0; i--){
            int mask = 1<<i;
            int bit = (mask & num) ? 0 : 1;
            if(bit == 0){
                if(curNode->children[0]){
                    curNode = curNode->children[0];
                    curMaxVal = curMaxVal | mask;
                }
                else{
                    curNode = curNode->children[1];
                }
            }
            else{
                if(curNode->children[1]){
                    curNode = curNode->children[1];
                    curMaxVal = curMaxVal | mask;
                }
                else{
                    curNode = curNode->children[0];
                }
            }
        }
        return curMaxVal;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(auto i:nums){
            insert(root, i);
        }
        int maxXOR = INT_MIN;
        for(auto i:nums){
            maxXOR = max(maxXOR, search(root, i));
        }
        return maxXOR;
    }
};

int main(){
    vector<int> nums = {3,10,5,25,2,8};
    Solution obj;
    auto answer = obj.findMaximumXOR(nums);
    cout << "Answer: " << answer << endl;
    return 0;
}