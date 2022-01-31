#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int generateNextSequentialNum(int curSequentialNum, int &curSequentialNumSize){
        int lastDigit = curSequentialNum%10;
        if(lastDigit == 9){
            curSequentialNumSize++;
            curSequentialNum = 12;
            for(int i=3; i<=curSequentialNumSize; i++){
                curSequentialNum*=10;
                curSequentialNum+=i;
            }
        }
        else{
            curSequentialNum*=10;
            curSequentialNum+=(lastDigit+1);
            curSequentialNum = curSequentialNum%(int)(pow(10, curSequentialNumSize));
        }
        return curSequentialNum;
    }

    vector<int> sequentialDigits(int low, int high) {
        int curSequentialNum = 12;
        int curSequentialNumSize = 2;
        vector<int> answer={};
        if(curSequentialNum>=low && curSequentialNum<=high){
            answer.push_back(curSequentialNum);
        }
        while(1){
            int generatedNum = generateNextSequentialNum(curSequentialNum, curSequentialNumSize);
            if(generatedNum <= high){
                if(generatedNum >= low){
                    answer.push_back(generatedNum);
                }
                curSequentialNum = generatedNum;                
            }
            else{
                break;
            }
        }
        return answer;       
        
    }
};

int main(){
    Solution obj;
    int low = 100;
    int high = 300;
    auto answer = obj.sequentialDigits(low, high);
    cout << "Answer: " << endl;
    for(auto i:answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}