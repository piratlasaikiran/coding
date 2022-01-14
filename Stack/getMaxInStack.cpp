#include <bits/stdc++.h>
using namespace std;

struct customStack{
    stack<int> values;
    int curMax=INT_MIN;

    void push(int val){
        if(values.empty()){
            values.push(val);
            curMax = val;
        }
        else if(val <= curMax){
            values.push(val);
        }
        else{
            int diff = 2*val - curMax;
            values.push(diff);
            curMax = val;
        }
    }

    void pop(){
        if(values.empty()){
            cout << "Stack is empty.!" << endl;
        }
        else if(values.top() < curMax)
            values.pop();
        else{
            curMax = 2*curMax - values.top();
            values.pop();
        }
    }

    void getMax(){
        if(values.empty())
            cout << "Stack is empty. No max value" << endl;
        else
            cout << "Current max: " << curMax << endl;
    }

    void getTop(){
        if(values.empty())
            cout << "Stack is empty. No top most value" << endl;
        else
            cout << "Current top element: " << values.top() << endl;
    }

};

int main(){
    customStack s;
    s.push(3);
    s.push(5);
    s.getMax();
    s.push(7);
    s.push(19);
    s.getMax();
    s.pop();
    s.getMax();
    s.pop();
    s.getTop();

    return 0;
}