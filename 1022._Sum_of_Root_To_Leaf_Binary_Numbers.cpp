/* You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer. */

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return depthFirstSearch(root, 0);
    }
    
    int depthFirstSearch(TreeNode* node, int currentSum) {
        // base case: if the current node is null, return 0
        if (!node) return 0;

        // Shift current sum left and add current node's value to it
        currentSum = (currentSum << 1) | node->val;

        // If we're at a leaf node, return the current sum
        if (!node->left && !node->right) return currentSum;

        // Recursively compute the sum for left and right children and return their sum
        return depthFirstSearch(node->left, currentSum) + depthFirstSearch(node->right, currentSum);
    }
};
