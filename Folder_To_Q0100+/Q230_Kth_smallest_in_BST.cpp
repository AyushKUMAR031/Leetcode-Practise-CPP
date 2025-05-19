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
    vector<int> mins;
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        mins.push_back(root->val);
        solve(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        return mins[k-1];
    }   
};

//without using vector
class Solution {
public:
    int count = 0;
    int ans = 0;
    void solve(TreeNode* root,int k){
        if(root == NULL) return;
        solve(root->left,k);
        count++;
        if(count == k) ans = root->val;
        solve(root->right,k);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};
