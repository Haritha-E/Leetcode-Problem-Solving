class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n1=nums1.length;
        int n2=nums2.length;
        int a[]=new int[n1];
        for(int i=0;i<n1;i++){
            boolean same=false;
            boolean found=false;
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    same=true;
                    continue;
                }
                if(same && nums1[i]<nums2[j]){
                        a[i]=nums2[j];
                        found=true;
                        break;
                }
            }
            if(!found)
                a[i]=-1;
        }
        return a;
    }
}