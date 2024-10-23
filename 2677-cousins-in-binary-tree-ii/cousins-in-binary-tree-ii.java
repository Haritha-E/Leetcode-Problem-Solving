/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    ArrayList<Integer> list = new ArrayList<>();
    public TreeNode replaceValueInTree(TreeNode root) {
        dfs(root,0);
        replacedfs(root,0);
        root.val=0;
        return root;
        
    }
    void dfs(TreeNode node,int level){
        if(node==null)return;
        
        if((list.size()-1)>=level){
            list.add(level,list.get(level)+node.val);
            list.remove(level+1);
        }else list.add(node.val);
        

        dfs(node.left,level+1);
        dfs(node.right,level+1);
    }
    void replacedfs(TreeNode node, int level){
        if(node==null)return;
        int l=0,r=0;
        if(node.left!=null)l=node.left.val;
        if(node.right!=null)r=node.right.val;

        if(node.left!=null){node.left.val=list.get(level+1)-(l+r);}
        if(node.right!=null){node.right.val=list.get(level+1)-(l+r);}

        replacedfs(node.left,level+1);
        replacedfs(node.right,level+1);

    }
}