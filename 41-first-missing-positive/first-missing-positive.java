class Solution {
    public int firstMissingPositive(int[] nums) {
        Arrays.sort(nums);
        int target=1;
        for(int i=0;i<nums.length;i++){
            if(target==nums[i]){
                target++;
            }
            else if(nums[i]>target){
                return target;
            }
        }
        return target;
    }
}