/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postordertraversal(root,result);
        return result;
    }

    void postordertraversal(Node* root, vector<int> &result){
        if(root==nullptr) return;
        for(auto child : root->children){
            postordertraversal(child,result);
        }
        result.push_back(root->val);
    }
};