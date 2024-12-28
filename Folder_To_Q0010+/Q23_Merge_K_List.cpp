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

//by vector
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        for(ListNode* root : lists){
            while(root!= NULL){
                v.push_back(root->val);
                root = root->next;
            }
        }
        sort(v.begin(),v.end());

        for(int i : v){
            insert(tail,i);
        }

        return head->next;
    }
    void insert(ListNode*& tail,int newval){
        ListNode* temp = new ListNode(newval);
        tail->next = temp;
        tail = temp;
    }
};

//by heap
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (ListNode* x : lists) {
            solve(x, pq);
        }
        while (!pq.empty()) {
            insert(tail, pq.top());
            pq.pop();
        }
        return head->next;
    }
    void insert(ListNode*& tail, int newval) {
        ListNode* temp = new ListNode(newval);
        tail->next = temp;
        tail = tail->next;
    }
    void solve(ListNode* root, priority_queue<int,vector<int>,greater<int>>& pq) {
        while (root != NULL) {
            pq.push(root->val);
            root = root->next;
        }
    }
};
