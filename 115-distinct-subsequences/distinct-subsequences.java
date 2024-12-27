class Solution {
    public int numDistinct(String s, String t) {
        int[][]dp = new int[s.length()+1][t.length()+1];
        for(int i=0;i<=t.length();i++){
            dp[0][i]=0;
        }
        for(int j=0;j<=s.length();j++){
            dp[j][0]=1;
        }
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                if(s.charAt(i-1)==t.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
}