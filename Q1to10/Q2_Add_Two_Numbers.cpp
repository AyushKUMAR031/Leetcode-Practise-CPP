class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumNode = new ListNode();
        ListNode* current = sumNode;
        int carry = 0,x,y;
        while(l1 != nullptr || l2 != nullptr){
            if(l1!=nullptr){
                x = l1->val;
                l1 = l1->next;
            }
            else{
                x = 0;
            }
            if(l2!=nullptr){
                y = l2->val;
                l2 = l2->next;
            }
            else{
                y = 0;
            }
            int sum = x+y+carry;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
        }
        if(carry==1){
            current->next = new ListNode(1);
        }
        return sumNode->next;

    }
};
