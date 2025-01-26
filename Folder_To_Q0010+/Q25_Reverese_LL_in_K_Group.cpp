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

    ListNode* reverseKGroup(ListNode* head, int k) {
        //base
        if(head == NULL){
            return NULL;
        }

        //step1 reverse first K nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        int count = 0;

        ListNode* temp = curr;
        while(count<k){
            if(temp==NULL){
                return curr;
            }
            temp=temp->next;  
            count++;
        }
        count = 0;
        while(curr != NULL && count < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        } 

        //step2 recurion dekhega
        if(forward != NULL){
            head -> next = reverseKGroup(forward,k);
        }    

        //step3 returning head of reveresed list.
        return prev;
    }
};
