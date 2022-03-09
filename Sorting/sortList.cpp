#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* traverser = head;
        vector<int> numTmpStore;
        while(traverser != nullptr){
            numTmpStore.push_back(traverser->val);
            traverser = traverser->next;
        }
        sort(numTmpStore.begin(), numTmpStore.end());
        int n = numTmpStore.size();
        traverser = head;
        for(int i=0; i<n; i++){
            traverser->val = numTmpStore[i];
            traverser = traverser->next;
        }
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(4);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    Solution obj;
    auto answer = obj.sortList(head);
    cout << "Answer: ";
    while(answer != nullptr){
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
    return 0;
}