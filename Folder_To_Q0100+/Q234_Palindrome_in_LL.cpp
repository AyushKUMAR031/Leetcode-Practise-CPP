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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        //finding mid
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow;

        //reversing 2nd half
        ListNode* prev = nullptr;
        ListNode* curr = middle;
        ListNode* forward = nullptr;

        while(curr!= nullptr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        //checking palindrome
        slow = head;  
        curr = prev;
        while(curr!= NULL){
            if(slow->val == curr->val){
                slow = slow->next;
                curr = curr->next;
            }else{
                return false;
            }
        } 

        //if ask we can also use the reversal to restore the original LL
        curr = prev;
        prev = nullptr;
        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return true;
    }
};
