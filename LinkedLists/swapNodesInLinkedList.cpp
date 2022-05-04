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
    ListNode* swapNodes(ListNode* head, int k) {
        int counter = 1;
        ListNode* left = head;
        ListNode* right = head;
        ListNode* traverser = head;
        while(traverser != nullptr){
            if(counter<k){
                left = left->next;
            }
            if(counter>=k){
                right = right->next;
            }
            traverser = traverser->next;
            counter++;
        }
        swap(left->val, right->val);
        return head;
    }
};