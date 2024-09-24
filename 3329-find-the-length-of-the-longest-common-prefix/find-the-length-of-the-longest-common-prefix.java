class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        int result=0;
        HashSet<Integer> set = new HashSet<>();
        for(int i=0; i<arr1.length; i++){
            int num = arr1[i];
            while(num>0){
                set.add(num);
                num = num/10;
            }
        }

        for(int i=0; i<arr2.length; i++){
            int num = arr2[i];
            int len=String.valueOf(num).length();  
            while(num>0){
                if(set.contains(num)){
                    result = Math.max(result, len);
                }
                num = num/10;
                len--;
            }
        }
        return result;
    }
}