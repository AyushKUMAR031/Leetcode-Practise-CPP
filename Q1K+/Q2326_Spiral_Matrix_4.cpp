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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int row = m, col = n;
        int top = 0,bottom = m-1,left = 0,right = n-1;

        //iteration is working like =  right->bottom->left->top

        while(top<=bottom && left<=right){

            //left to right
            for(int i=left;i<=right;i++){
                if(head != nullptr){
                    matrix[top][i]= head->val;
                    head= head->next;
                }
            }
            top++;

            //top to bottom
            for(int i=top;i<=bottom;i++){
                if(head !=nullptr){
                    matrix[i][right]= head->val;
                    head = head->next;
                }
            }
            right--;

            //right to left
            for(int i=right;i>=left;i--){
                if(head!=nullptr){
                    matrix[bottom][i]= head->val;
                    head = head->next;
                }
            }
            bottom--;

            //bottom to top
            for(int i=bottom;i>=top;i--){
                if(head!=nullptr){
                    matrix[i][left]= head->val;
                    head = head->next;
                }
            }
            left++;
        }
        return matrix;
    }
};
