//code
class Solution {
public:
    int maxsum = INT_MIN;

    int solve(TreeNode* root){
        if( root == NULL) return 0;
        int left = max(0,solve(root->left)); //comparing with 0 to remove -ve nums.
        int right = max(0,solve(root->right));

        int currentmax = left + right + root->val;
        maxsum = max(currentmax, maxsum);

        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};
