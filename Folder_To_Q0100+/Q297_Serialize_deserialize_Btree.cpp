/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    /*
        1
       / \
      2   3
         / \
        4   5
        Becomes → "1,2,NULL,NULL,3,4,NULL,NULL,5,NULL,NULL,"
    */

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(root == NULL ) return "NULL,";
       return to_string(root->val)+","+serialize(root->left)+serialize(root->right); 
    }

    //creating array from string
    void split(const string &data, vector<string> &tokens) {
        string token;
        stringstream ss(data); // Creates a stringstream object named ss.
        //helps to extract parts from it with getline

        while(getline(ss,token,',')){
            tokens.push_back(token); //pushing token string into tokens vector
        }

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        split(data,tokens);

        int index = 0;
        return buildTree(tokens,index);
    }

    private:

    TreeNode* buildTree(vector<string> &tokens, int &index) {
        if (tokens[index] == "NULL") {
            index++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(tokens[index++])); //string to int
        node->left = buildTree(tokens, index);
        node->right = buildTree(tokens, index);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
