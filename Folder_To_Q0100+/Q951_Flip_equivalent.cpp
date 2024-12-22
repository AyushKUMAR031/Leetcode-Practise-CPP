Solution
Overview
We are given the roots of two binary trees and we are asked to determine whether they are flip equivalent. To clarify, let’s break down the two key terms involved:

Flip Operation:
A flip operation involves selecting any node in the tree and swapping its left and right subtrees. The node's value and the internal structure of its subtrees remain unchanged. The only modification is that the positions of the node's direct children are swapped.

For example, consider the tree below. The tree on the left shows the initial structure, and the tree on the right shows the result after performing a flip on node 1.

Flip operation example

Equivalent Trees:
Two binary trees are considered equivalent if they satisfy the following conditions:

Same structure: The arrangement of nodes and their subtrees (left and right) are identical.
Same node values: Every corresponding node in both trees has the same value.
In this context, we want to determine whether two given binary trees can become equivalent by applying flip operations as needed.

Approach 1: Recursion (Top-down Traversal)
Intuition
Since binary trees are inherently recursive structures, a recursive approach is intuitive.

For each node, we have two possible options: either we swap its left and right subtrees, or we leave them as they are. We explore both possibilities for every node, starting from the root. If any sequence of flips results in the two trees becoming equivalent, our function will return true, indicating that the trees are flip equivalent. If no valid sequence leads to equivalence, the function returns false.

Algorithm
If both root1 and root2 are empty trees, they are considered flip equivalent according to the definition provided; return true.
If only one of root1 or root2 is empty, they are not flip equivalent, as they do not satisfy the structural property of equivalence; return false.
If root1 and root2 have different node values, the trees are not flip equivalent, since this means their corresponding nodes differ; return false.

Recursively check two scenarios for flip equivalence:

No Swap: Check if the left subtree of root1 is flip equivalent to the left subtree of root2 and the right subtree of root1 is flip equivalent to the right subtree of root2.
Swap: Check if the left subtree of root1 is flip equivalent to the right subtree of root2 and the right subtree of root1 is flip equivalent to the left subtree of root2.
Return true if either the noSwap or swap conditions are satisfied, as this confirms flip equivalence for the current nodes and their subtrees.

Implementation

Complexity Analysis
Let N be the number of nodes in the smaller tree.

Time Complexity: O(N).
This is because the recursion stops at the leaf nodes or when a mismatch occurs. In the worst case, every node in the smaller tree will be visited.

Space Complexity: O(N).
This is due to the recursion stack. In the worst case, the recursion goes as deep as the tree's height, which can be O(N) in the case of a skewed tree (a tree in which every internal node has only one child). For a balanced tree, the space complexity will be O(logN) because the tree's height would be logarithmic relative to the number of nodes.

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1,root2);
    }
private:
    bool check(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1->val != root2->val)
            return false;
        
        //basically direct child are swapped and nested are not swapped
        //for flip
        bool swap =  check(root1->left,root2->right) && check(root1->right,root2->left);

        //if direct children are not flipped
        bool noswap = check(root1->left,root2->left) && check(root1->right,root2->right);

        //if any true then true is returned
        return swap || noswap;
    }
};
