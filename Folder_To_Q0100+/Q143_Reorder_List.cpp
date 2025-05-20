class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL ) return;

        //step1 : going to the mid of the list
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        //step2 : reversing the second half i.e from slow->next.
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        //step3 :
        slow->next = nullptr; //with this the two halfs are now detached and r independent

        //step4 : merging the two halfs with alternative nodes.
        ListNode* first = head;
        ListNode* second = prev;

        while(first != NULL && second != NULL){
            ListNode* temp1 = first->next; //storing next ,so that link break na ho
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            second = temp2; //avoid dangling ptr
            first = temp1;
        }

    }
};
