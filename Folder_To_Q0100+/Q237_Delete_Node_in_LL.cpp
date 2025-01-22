//time complexity -> o(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
//same no effect
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* n = node->next;
        node->val = n->val;
        node->next = n->next;
        delete n;
    }
};
