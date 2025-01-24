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
        ListNode* dummy = new ListNode(0, head); //creating a dummy if left == head then,
        //nothing is behind head.
        ListNode* mark1 = dummy;

        int count = 1;
        while (count < left) {
            mark1 = mark1->next;
            count++;
        }

        ListNode* prev = NULL;
        ListNode* curr = mark1->next;
        ListNode* mark2 = curr;
        ListNode* forward = NULL;

        for (int i = left; i <= right; i++) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        mark1->next = prev;
        mark2->next = curr;

        return dummy->next; //returning dummy->next actual starting point
    }
};
