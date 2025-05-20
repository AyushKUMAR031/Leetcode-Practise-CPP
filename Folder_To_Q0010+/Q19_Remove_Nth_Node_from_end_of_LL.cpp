class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);  // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches end
        while(fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp; // Optional: avoid memory leak

        return dummy->next;
    }
};
