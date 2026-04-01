/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution { 
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rc = new ListNode();
        ListNode* curr = rc;
        int carry = 0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int val = (l1? l1->val: 0) + (l2? l2->val: 0) + carry;
            carry = val/10;
            val = val%10;
            curr->next = new ListNode(val);
            curr = curr->next;
            l1 = (l1 != nullptr)? l1->next : nullptr;
            l2 = (l2 != nullptr)? l2->next : nullptr;
        }
        ListNode* tmp = rc;
        rc = rc->next;
        delete tmp;
        return rc;
    }
};
