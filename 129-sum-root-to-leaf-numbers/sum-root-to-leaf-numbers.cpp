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
    void pathSum(TreeNode* root,int rs, int &s){
        if(root==NULL)
            return;
        if(!root->left && !root->right)
            s=s+rs*10 + root->val;
        pathSum(root->left, rs*10 + root->val, s);
        pathSum(root->right, rs*10 + root->val, s);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        pathSum(root,0,sum);
        return sum;
    }
};