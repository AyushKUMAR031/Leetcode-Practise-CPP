class Solution {
public:
    void insertAtTail(Node* &CloneHead,Node* &CloneTail,int val){
        Node* curr = new Node(val);
        if(CloneHead == NULL){
            CloneHead = curr;
            CloneTail = curr;
            return;
        }
        CloneTail->next = curr;
        CloneTail = curr;
    }

    Node* copyRandomList(Node* head) {

        //step 1 : create a Clone List
        Node* CloneHead = NULL;
        Node* CloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(CloneHead,CloneTail,temp->val);
            temp = temp->next;
        }

        //Step 2 : Create a Mapping for the Randoms
        unordered_map<Node*,Node*> realToClone;
        Node* real = head;
        Node* clone = CloneHead;
        while(real != NULL && clone != NULL){
            realToClone[real] = clone;
            real = real->next;
            clone = clone->next;
        }

        //adding Randoms to the clone LL
        clone = CloneHead;
        real = head;
        while(clone != NULL){
            clone->random = realToClone[real->random];
            real = real->next;
            clone = clone->next;
        }

        return CloneHead;
    }
};
