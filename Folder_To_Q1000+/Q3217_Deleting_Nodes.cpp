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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *current = head;
        ListNode *prev = new ListNode();
        unordered_set<int> nums_set;

        nums_set.insert(nums.begin(),nums.end());

        while(current != nullptr){
            int checknum = current->val;

            if(nums_set.find(checknum) != nums_set.end()){
               if(checknum == head->val){
                head = head->next;
                current = head;
                prev = head;
               }else{
                prev->next = current->next;
                current = current->next;
               }
            }else{
                prev = current;
                current = current->next;
            }
        }
        return head;
    }
};
