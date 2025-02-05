class Solution {
public:
    int solve(TreeNode* root, bool &flag){
        if(root == NULL) return 0;

        int l = solve(root->left,flag);
        int r = solve(root->right,flag);
        if(abs(l - r) > 1){
            flag = false;
        }
        return max(l,r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL ) return true;
        bool flag = true;
        solve(root,flag);
        return flag;
    }
};
