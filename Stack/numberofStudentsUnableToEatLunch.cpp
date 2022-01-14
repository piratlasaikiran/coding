#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> kids;
        stack<int> tiffin;
        int n = students.size();
        int circularSandwich=0;
        int squareSandwich=0;
        int kidsLinkingCircularSandwich=0;
        int kidsLikingSquareSandwich=0;
        for(int i=0; i<n; i++){
            kids.push_back(students[i]);
            tiffin.push(sandwiches[n-1-i]);
            if(students[i]==0){
                kidsLinkingCircularSandwich++;
            }
            else{
                kidsLikingSquareSandwich++;
            }
            if(sandwiches[i]==0){
                circularSandwich++;
            }
            else{
                squareSandwich++;
            }
        }

        int kidsWithDesiredTiffin=0;
        while(true){
            if(!tiffin.empty() && !kids.empty() && kids.front() == tiffin.top()){
                cout << "Kid with pref: " << kids.front() << " took sandwich: " << tiffin.top() << endl;
                if(tiffin.top() == 0){
                    circularSandwich--;
                    kidsLinkingCircularSandwich--;
                }
                else{
                    squareSandwich--;
                    kidsLikingSquareSandwich--;
                }
                tiffin.pop();
                kids.pop_front();
                kidsWithDesiredTiffin++;
                
            }
            else{
                kids.push_back(kids.front());
                kids.pop_front();
            }
            if(tiffin.empty() || (!tiffin.empty() && tiffin.top()==0 && kidsLinkingCircularSandwich==0) || (!tiffin.empty() && tiffin.top()==1 && kidsLikingSquareSandwich==0))
                break;
        }
        return n-kidsWithDesiredTiffin;

    }
};

int main(){
    Solution obj;
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    auto answer = obj.countStudents(students, sandwiches);
    cout << "Answer: " << answer << endl;
    return 0;
}