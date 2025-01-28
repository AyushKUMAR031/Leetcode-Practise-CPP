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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
       ListNode* curr = head;
       ListNode* forward = head->next;
       ListNode* connect = forward;

       while(forward != NULL && forward->next != NULL){
            curr->next = curr->next->next;
            curr = curr->next;

            forward->next = forward->next->next;
            forward = forward->next;
       }
       curr->next = connect;

       return head;
    }
};
