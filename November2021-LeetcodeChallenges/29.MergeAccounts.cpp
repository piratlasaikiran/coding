#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> disjointUnionFind;

    int findP(int element){
        if(disjointUnionFind[element] == element)
            return element;
        return findP(disjointUnionFind[element]);
    }

    void unionOperation(int from, int to){
        int fromP = findP(from);
        int toP = findP(to);
        disjointUnionFind[fromP] = toP;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToNames;
        int n = accounts.size();
        disjointUnionFind.resize(n);
        for(int i=0; i<n; i++)
            disjointUnionFind[i] = i;            
        for(int userIndex = 0; userIndex<accounts.size(); userIndex++){
            auto userAccount = accounts[userIndex];
            for(int i=1; i<userAccount.size(); i++){
                if(emailToNames.find(userAccount[i]) == emailToNames.end()){
                    emailToNames[userAccount[i]] = userIndex;
                }
                else{
                    unionOperation(userIndex, emailToNames[userAccount[i]]);
                }
                
            }
        }
        for(auto i:emailToNames)
            cout << i.first << " " << i.second << endl;
        for(auto i:disjointUnionFind)
            cout << i << " ";
        cout << endl;
        map<int, set<string>> userMails;
        for(auto it:emailToNames){
            userMails[findP(emailToNames[it.first])].insert(it.first);
        }
        vector<vector<string>> answer;
        for(auto it:userMails){
            vector<string> userDetails={};
            userDetails.push_back(accounts[it.first][0]);
            for(auto mail:it.second){
                userDetails.push_back(mail);
            }
            answer.push_back(userDetails);
        }
    return answer;
    }
    
};

int main(){
    Solution obj;
    vector<vector<string>> account = {{"Alex","Alex5@m.co","Alex4@m.co","Alex0@m.co"},{"Ethan","Ethan3@m.co","Ethan3@m.co","Ethan0@m.co"},{"Kevin","Kevin4@m.co","Kevin2@m.co","Kevin2@m.co"},{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe2@m.co"},{"Gabe","Gabe3@m.co","Gabe4@m.co","Gabe2@m.co"}};
    auto answer = obj.accountsMerge(account);
    for(auto i:answer){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}