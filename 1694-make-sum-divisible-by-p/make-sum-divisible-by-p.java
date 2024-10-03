import java.util.HashMap;

class Solution {
    public int minSubarray(int[] nums, int p) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        if (totalSum == 0) return 0; 
        
        HashMap<Integer, Integer> prefixSumIndex = new HashMap<>();
        prefixSumIndex.put(0, -1); 
        
        int prefixSum = 0, minLen = nums.length;
        for (int i = 0; i < nums.length; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - totalSum + p) % p;
            
            if (prefixSumIndex.containsKey(target)) {
                minLen = Math.min(minLen, i - prefixSumIndex.get(target));
            }
            
            prefixSumIndex.put(prefixSum, i); 
        }
        
        return minLen == nums.length ? -1 : minLen;
    }
}