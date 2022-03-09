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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curTraverser = head;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevTraverser = dummy;
        ListNode* nextTraverser = head->next;
        ListNode* nextIterPointer = head->next->next;
        
        while(curTraverser != nullptr && nextTraverser != nullptr){
            curTraverser->next = nextIterPointer;
            nextTraverser->next = curTraverser;
            prevTraverser->next = nextTraverser;

            prevTraverser = curTraverser;
            curTraverser = nextIterPointer;
            nextTraverser = nullptr;
            nextIterPointer = nullptr;
            if(curTraverser != nullptr){
                nextTraverser = curTraverser->next;
                if(curTraverser->next != nullptr){
                    nextIterPointer = curTraverser->next->next;
                }
            }

        }
        return dummy->next;

    }
};

int main(){
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);

    Solution obj;
    auto answer = obj.swapPairs(root);
    cout << "Answer: " ;
    while(answer != nullptr){
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
    return 0;
}