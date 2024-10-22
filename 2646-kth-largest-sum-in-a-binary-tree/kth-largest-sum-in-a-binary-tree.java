import java.util.*;

class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        if (root == null) return -1;
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);  
        while (!queue.isEmpty()) {
            int levelSize = queue.size();  
            long levelSum = 0; 
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();  
                levelSum += node.val; 
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            if (minHeap.size() < k) {
                minHeap.add(levelSum);
            } else if (levelSum > minHeap.peek()) {
                minHeap.poll();
                minHeap.add(levelSum);
            }
        }
        return minHeap.size() == k ? minHeap.peek() : -1;
    }
}