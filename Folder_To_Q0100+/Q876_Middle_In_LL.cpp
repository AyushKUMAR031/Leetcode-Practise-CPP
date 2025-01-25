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
    ListNode* middleNode(ListNode* head) {
        ListNode* m1 = head;
        int count = 1;
        while(m1->next != nullptr){
            count++;
            m1 = m1->next;
        }

        int mid = (count)/2 + 1 ;
    
        m1 = head;
        count = 1;
        while(count<mid){
            m1 = m1->next;
            count++;
        }

        return m1;
    }
};


//New Trick of Fast and Slow Pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;

        while(fastPointer != nullptr && fastPointer->next != nullptr){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
};
