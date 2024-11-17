class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length, minLength = Integer.MAX_VALUE;
        long[] prefixSum = new long[n + 1];
        Deque<Integer> deque = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int i = 0; i <= n; i++) {
            while (!deque.isEmpty() && prefixSum[i] <= prefixSum[deque.getLast()]) {
                deque.pollLast();
            }
            while (!deque.isEmpty() && prefixSum[i] - prefixSum[deque.peek()] >= k) {
                minLength = Math.min(minLength, i - deque.poll());
            }
            deque.add(i);
        }
        return minLength == Integer.MAX_VALUE ? -1 : minLength;
    }
}