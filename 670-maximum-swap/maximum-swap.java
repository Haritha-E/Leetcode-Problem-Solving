class Solution {
    public int maximumSwap(int num) {
        String s = String.valueOf(num);
        char[] iter = s.toCharArray();
        int n = s.length();
        int[] mins = new int[n];
        int minIndex = 0;
        mins[0] = 0;
        for (int i = 1; i < n; i++) 
        {
            if (iter[i] < iter[minIndex]) 
            {
                minIndex = i;
            }
            mins[i] = minIndex;
        }
        int[] maxs = new int[n];
        int maxIndex = n - 1;
        maxs[n - 1] = n - 1; 

        for (int i = n - 2; i >= 0; i--) 
        {
            if (iter[i] > iter[maxIndex]) 
            {
                maxIndex = i;
            }
            maxs[i] = maxIndex;
        }
        for (int i = 0; i < n; i++) 
        {
            if (iter[maxs[i]] > iter[i]) 
            {
                char temp = iter[i];
                iter[i] = iter[maxs[i]];
                iter[maxs[i]] = temp;
                return Integer.parseInt(new String(iter));
            }
        }

        return num;
    }
}