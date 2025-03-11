/* You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children. */

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int currentSum) {
        if (!root) return 0;
        currentSum = currentSum * 10 + root->val;
        if (!root->left && !root->right) return currentSum;
        return helper(root->left, currentSum) + helper(root->right, currentSum);
    }
};
