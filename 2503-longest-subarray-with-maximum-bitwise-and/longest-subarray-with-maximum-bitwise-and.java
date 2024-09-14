class Solution {
    public int longestSubarray(int[] nums) {
      int len=0;
      int max=0;
      for(int i=0;i<nums.length;i++){
        max=Math.max(max,nums[i]);
      }
        int count=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==max){
                count++;
                len=Math.max(len,count);
            }else{
                count=0;
            }
        }
      return len;  
    }
}