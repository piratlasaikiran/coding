#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string decodedString="";
    stack<int> numStack;
    stack<char> charStack;

    void multiplyTheString(string s, int multiplier){
        cout << s << " should be multiplied " << multiplier << " times." << endl;
        string multipliedByMultiplier = s;
        for(int i=0; i<multiplier-1; i++){
            for(int j=0; j<s.size(); j++){
                multipliedByMultiplier.push_back(s[j]);
            }
        }

        decodedString+=multipliedByMultiplier;
    }

    void addThisStackToString(){
        string remCharStack = "";
        while(!charStack.empty()){
            remCharStack.insert(remCharStack.begin(), charStack.top());
            charStack.pop();
        }
        decodedString+=remCharStack;
    }
    

    string decodeString(string s) {
        int l = s.size();
        int start=0;
        numStack.push(-1);
        while(start<l){
            char c = s[start];
            if(c>'0' && c<='9'){
                numStack.push(c-'0');
                if(!charStack.empty())
                    addThisStackToString();
            }
            else if(c==']'){
                string multiplicant="";
                char multiplicantChar;
                while(charStack.top() != '['){
                    multiplicantChar = charStack.top();
                    charStack.pop();
                    multiplicant.insert(multiplicant.begin(), multiplicantChar);
                }
                charStack.pop();
                int base=0;
                int multiplier=0;
                while(numStack.top() != -1){
                    int digit = numStack.top();
                    numStack.pop();
                    multiplier = multiplier + digit*pow(10, base);
                    base++;
                }
                multiplyTheString(multiplicant, multiplier);
            }
            else{
                charStack.push(c);
            }
            start++;
        }
        addThisStackToString();

        return decodedString;
    }
};


class anotherSolution{
    public:

    void multiplyTheString(string s, int multiplier, stack<char>& charStack){
        cout << s << " should be multiplied " << multiplier << " times." << endl;
        for(int i=0; i<multiplier; i++){
            for(int j=0; j<s.size(); j++){
                charStack.push(s[j]);
            }
        }
    }

    string addThisStackToString(stack<char>& charStack){
        string decodedString = "";
        while(!charStack.empty()){
            decodedString.insert(decodedString.begin(), charStack.top());
            charStack.pop();
        }
        return decodedString;
    }

    string decodeString(string s){
        stack<char> charStack;
        int n = s.size();
        int start = 0;
        char multiplicantChar;
        string multiplicant;
        while(start<n){
            if(s[start] == ']'){
                multiplicant="";
                while(!charStack.empty() && charStack.top() != '['){
                    multiplicantChar = charStack.top();
                    charStack.pop();
                    multiplicant.insert(multiplicant.begin(), multiplicantChar);
                }
                if(!charStack.empty())
                    charStack.pop();
                int base=0;
                int multiplier=0;
                while((!charStack.empty() && charStack.top() >= '0' && charStack.top() <= '9')){
                    int digit = charStack.top() - '0';
                    charStack.pop();
                    multiplier = multiplier + digit*pow(10, base);
                    base++;
                }
                multiplyTheString(multiplicant, multiplier, charStack);
            }
            else{
                charStack.push(s[start]);
            }
            start++;
        }

        return addThisStackToString(charStack);

    }

};

int main(){
    anotherSolution obj;
    string input = "3[a]2[bc]";
    auto answer = obj.decodeString(input);
    cout << "Answer: " << answer << endl;
    return 0;
}