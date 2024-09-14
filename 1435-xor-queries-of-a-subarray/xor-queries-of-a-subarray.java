class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] preXOR = new int[arr.length];
        preXOR[0] = arr[0];
        for(int i=1; i<arr.length; ++i)
            preXOR[i] = arr[i] ^ preXOR[i-1];

        int n = queries.length;
        int[] result = new int[n];
        for(int i=0; i<n; ++i) {
            result[i] = preXOR[queries[i][1]];

            if(queries[i][0] > 0)
                result[i] ^= preXOR[queries[i][0] -1];
        }

        return result;

    }
}