/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int value) {
        if(root == NULL){
            TreeNode* newNode = new TreeNode(value);
            return newNode;
        }       
        if(value < root->val)
            root->left = insertIntoBST(root->left,value);
        if(value > root->val)
            root->right = insertIntoBST(root->right,value);
        return root; 
    }
};
