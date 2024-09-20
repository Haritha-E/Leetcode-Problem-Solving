
class Solution {
    public String shortestPalindrome(String s) {
        int i = 0;
        int n = s.length();
        int j = n - 1;
        while (j >= 0) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
            }
            j--;
        }        
        if (i == n) {
            return s;
        }
        String p = new StringBuilder(s.substring(i, n)).reverse().toString();
        return p + shortestPalindrome(s.substring(0, i)) + s.substring(i);
    }
}