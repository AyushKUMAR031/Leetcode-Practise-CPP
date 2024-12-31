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
    void solve(TreeNode* root,vector<int>& ans){
        if(root == NULL) return;
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans;
    }
};


//by two stack
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
    void solve(TreeNode* root,stack<TreeNode*>& s1,stack<TreeNode*>& s2){
        if(root == NULL) return;
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s2.push(root);
            s1.pop();
            if(root->left != nullptr) s1.push(root->left);
            if(root->right != nullptr) s1.push(root->right);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        solve(root,s1,s2);
        
        vector<int> ans;

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};
