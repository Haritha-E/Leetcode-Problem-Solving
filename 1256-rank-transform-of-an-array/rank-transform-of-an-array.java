class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        int[] org = Arrays.copyOf(arr, n);
        Arrays.sort(arr);
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 1;
        for(int i=0; i<n; i++){
            if(!map.containsKey(arr[i])){
            map.put(arr[i], count);
            count++;
            }
        }
        int[] ans = new int[n];
        int j=0;
         for (int i = 0; i < n; i++) {
            ans[i] = map.get(org[i]); 
        }
        return ans;
    }
}