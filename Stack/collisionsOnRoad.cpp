//https://www.youtube.com/watch?v=epv_QKu-P5E
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int collisionCount = 0;
        int left = 0;
        int right = n-1;
        while(left < n && directions[left]=='L'){
            left++;
        }
        while(right >= 0 && directions[right]=='R'){
            right--;
        }
        for(int i=left; i<=right; i++){
            if(directions[i] != 'S'){
                collisionCount++;
            }
        }
        return collisionCount;
    }
};

int main(){
    string directions = "RLRSLL";
    Solution obj;
    auto answer = obj.countCollisions(directions);
    cout << "Answer: " << answer << endl;
    return 0;
}