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
    bool solve(TreeNode* sub1,TreeNode* sub2){
        if(sub1 == nullptr && sub2 == nullptr)
            return true;

        if(sub1 == nullptr || sub2 == nullptr)
            return false;

        if(sub1->val != sub2->val)
            return false;
        
        if(!solve(sub1->left,sub2->right))
            return false;
        if(!solve(sub1->right,sub2->left))
            return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return solve(root->left,root->right);
    }
};
