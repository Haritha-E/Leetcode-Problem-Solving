class Solution {
    Set<String> dct;
    int dp[];
    public int minExtraChar(String s, String[] dictionary) {
        dct = new HashSet<>(); int n = s.length();
        dp = new int[n+1];
        Arrays.fill(dp,-1);
        for(String st:dictionary){
            dct.add(st);
        }
        return solve(s,0,s.length());
    }
    
    public int solve(String s,int i,int n){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int take = 0;
        int skip = 1 + solve(s,i+1,n);
        for(int j = i; j < n ; j++){
            String  sub = s.substring(i,j+1);
            if(dct.contains(sub)){
                skip = Math.min(skip,solve(s,j+1,n));
            }
        }
        return dp[i] =  skip;
    }
}