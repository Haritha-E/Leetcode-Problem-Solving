class Solution {
    public int[] productExceptSelf(int[] nums) {
        int p = 1;
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        left[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            p *= nums[i - 1];
            left[i] = p;
        }
        p = 1;
        right[nums.length - 1] = 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            p *= nums[i + 1];
            right[i] = p;
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = left[i] * right[i];
        }
        return nums;
    }
}