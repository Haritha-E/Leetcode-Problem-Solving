import java.util.List;
import java.util.PriorityQueue;
import java.util.Arrays;

class Solution {
    class Pair {
        int val;
        int listIndex;
        int index;
        Pair(int val, int listIndex, int index) {
            this.val = val;
            this.listIndex = listIndex;
            this.index = index;
        }
    }
    
    public int[] smallestRange(List<List<Integer>> nums) {
        int n = nums.size();
        int[] ans = new int[2];
        int[] list = new int[n];
        int range = Integer.MAX_VALUE;
        Arrays.fill(list, 0);
        int maxi = Integer.MIN_VALUE;
        PriorityQueue<Pair> q = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (int i = 0; i < n; i++) {
            q.offer(new Pair(nums.get(i).get(0), i, 0));
            maxi = Math.max(maxi, nums.get(i).get(0));
        }
        int mini = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            Pair current = q.poll();
            mini = current.val;
            int listIndex = current.listIndex;
            int index = current.index;
            if (maxi - mini < range) {
                range = maxi - mini;
                ans[0] = mini;
                ans[1] = maxi;
            }
            if (index + 1 < nums.get(listIndex).size()) {
                int nextVal = nums.get(listIndex).get(index + 1);
                q.offer(new Pair(nextVal, listIndex, index + 1));
                maxi = Math.max(maxi, nextVal); 
            } else {
                break; 
            }
        }
        return ans;
    }
}