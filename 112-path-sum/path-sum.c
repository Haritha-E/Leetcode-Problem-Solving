/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {

    if(root == NULL) return false;
    if(!root ->left && !root -> right)
    {
        return targetSum - root ->val == 0;
    }

    return hasPathSum(root -> left , targetSum - root -> val) ||
    hasPathSum(root -> right , targetSum - root -> val);
}