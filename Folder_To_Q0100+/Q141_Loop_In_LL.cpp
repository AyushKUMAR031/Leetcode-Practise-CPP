/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//81% beats
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* marker = head;
        ListNode* walker = head;

        while(walker != NULL && walker->next != NULL){
            marker = marker->next;
            walker = walker->next->next;
            if(walker == marker){
                return true;
            }
        }
        return false;
    }
};

//best
if(head == nullptr || head->next == nullptr) return false; //adding this line beats 97%

//another way but not good but new way
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        map<ListNode*,bool> visited;

        ListNode* temp = head;
        while(temp != NULL){

            //cycle present hai
            if(visited[temp] == true){
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};
