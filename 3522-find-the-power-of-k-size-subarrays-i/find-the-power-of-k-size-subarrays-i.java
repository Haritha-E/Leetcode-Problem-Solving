class Solution {
    public boolean isconsecutive(int[] nums,int a,int b){
        for(int i=a;i<b-1;i++){
            if(nums[i]+1!=nums[i+1])return false;
        }
        return true;
    }
    public int ans(int []nums,int a,int b){
        int res=-1;
        for(int y=a;y<b;y++){
            res = Math.max(res,nums[y]);
        }
        return res;
    }
    public int[] resultsArray(int[] nums, int k) {
        int [] arr =  new int[nums.length-k+1];
        int i=0;
        for(int j=0;j<nums.length-k+1;j++){
            if(isconsecutive(nums,j,j+k)){
                arr[i++]=ans(nums,j,j+k);
            }else{
                arr[i++]=-1;
            }
        }
        return arr;
    }
}