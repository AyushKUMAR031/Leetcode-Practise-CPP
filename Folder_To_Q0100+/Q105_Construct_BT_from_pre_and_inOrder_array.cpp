
class Solution {
public:
    unordered_map<int,int> inMap; //for storing the value of node with the index from inorder.
    int currIndex = 0;
    TreeNode* create(vector<int>& preorder,vector<int>& inorder,int instart,int inend){
        if( instart > inend ) return nullptr; //checking recursion is within limits.

        int rootval = preorder[currIndex]; //with preorder values creating curr rootval.
        currIndex++;
        TreeNode* root = new TreeNode(rootval); //now creating a node for that value.


        int inIndex = inMap[rootval]; //checking where is rootval in inorder array.

        
        root->left = create(preorder,inorder,instart,inIndex-1); //passing to root ka left
        root->right = create(preorder,inorder,inIndex+1,inend); //passing to root ka right

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }

        return create(preorder,inorder,0,inorder.size()-1);
    }
};
