#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        
        string st{};
        int l1 = num1.size();
        int l2 =num2.size();
        vector<int> result(l1+l2, 0);
        int product=0;
        for(int i=l1-1; i>=0; i--){            
            for(int j=l2-1; j>=0; j--){                
                product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i+j+1];
                result[i+j+1] = sum % 10;
                result[i+j] += sum / 10;
            }
        }
        
		string productString = "";
        for(int i=0; i<l1+l2; i++){
            if(result[i] || productString.size())
                productString.append(to_string(result[i]));
        }
        
        if(productString.size() == 0)
            productString = "0";
        return productString;
    }
};


    int main(){
    Solution obj;
    string s1="123456789", s2="987654321";
    auto answer = obj.multiply(s1, s2);

    cout << "Answer: " << answer << endl;

    // for(auto j:answer)
    //     cout << j << " ";
    // cout << endl;

    return 0;
}

