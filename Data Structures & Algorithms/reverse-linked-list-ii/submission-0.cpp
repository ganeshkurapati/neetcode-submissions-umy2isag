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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;
        for(int i=0; i<left-1; i++) prev = prev->next;

        ListNode* leftNode = prev->next;
        ListNode* rightNode = leftNode;
        for(int i=0; i< right-left; i++) {
            rightNode = rightNode->next;
        }
        ListNode* rightNext = rightNode->next;
        rightNode->next = nullptr;
        prev->next = reverseList(leftNode);
        leftNode->next = rightNext;
        return dummy.next;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};