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


//best - 100%
class Solution {
public:
    void insertatTail(ListNode* &anshead,ListNode* &ansTail,int digit){
        ListNode* temp = new ListNode(digit);
        if(anshead == NULL){
            anshead = temp;
            ansTail = temp;
        }else{
            ansTail->next = temp;
            ansTail = temp;
        }
    }

    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* anshead = NULL;
        ListNode* ansTail = NULL;
        while(l1 != NULL && l2 != NULL){
            int sum = carry + l1->val + l2->val;
            int digit = sum%10;
            //create node and add it in ans LL
            insertatTail(anshead,ansTail, digit);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int sum = carry + l1->val;
            int digit = sum%10;
            //create node and add it in ans LL
            insertatTail(anshead,ansTail, digit);
            carry = sum/10;
            l1 = l1->next;
        }

        while(l2 != NULL){
            int sum = carry + l2->val;
            int digit = sum%10;
            //create node and add it in ans LL
            insertatTail(anshead,ansTail, digit);
            carry = sum/10;
            l2 = l2->next;
        }

        while(carry != 0){
            int sum = carry ;
            int digit = sum%10;
            //create node and add it in ans LL
            insertatTail(anshead,ansTail, digit);
            carry = sum/10;
        }
        return anshead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //adding the number
        ListNode* ans = add(l1,l2);
        //bye bye 
        return ans;
    }
};

//more good looking - 100%
class Solution {
public:
    void insertatTail(ListNode* &anshead,ListNode* &ansTail,int digit){
        ListNode* temp = new ListNode(digit);
        if(anshead == NULL){
            anshead = temp;
            ansTail = temp;
        }else{
            ansTail->next = temp;
            ansTail = temp;
        }
    }

    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* anshead = NULL;
        ListNode* ansTail = NULL;

        while(l1 != NULL || l2 != NULL || carry != 0){
            int val1 = 0;
            if(l1 != NULL)
                val1 = l1->val;
            int val2 = 0;
            if(l2 != NULL)
                val2 = l2->val;
            
            int sum = carry + val1 + val2;
            int digit = sum%10;

            //create node and add it in ans LL
            insertatTail(anshead,ansTail, digit);
            carry = sum/10;
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        return anshead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //adding the number
        ListNode* ans = add(l1,l2);
        //bye bye 
        return ans;
    }
};
