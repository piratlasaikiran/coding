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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;

        ListNode* tmp;
        if(l1->val > l2->val){
            tmp = l1;
            l1 = l2;
            l2 = tmp;
        }

        ListNode* reference = l1;
        ListNode* traverser2 = l2;
        ListNode* prevNode1 = l1;

        l1 = l1->next;
        while(l1 && l2){
            cout << l1->val << " " << l2->val << endl;
            if(l2->val <= l1->val){
                prevNode1->next = l2;
                traverser2 = l2->next;
                l2->next = l1;
                l2 = traverser2;
                prevNode1 = prevNode1->next;
            }
            else{
                prevNode1 = l1;
                l1 = l1->next;
            }
        }
        if(l2)
            prevNode1->next = l2;

        return reference;
    }
};

int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    Solution obj;
    auto answer = obj.mergeTwoLists(l1, l2);

    while(answer){
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
    return 0;
}