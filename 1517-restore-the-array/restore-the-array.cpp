#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define PII pair<int, int>
#define VPII vector<PII>
#define x first
#define y second
const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vl dp(n + 1, 0), pfx(n + 1, 0);   
        dp[n] = 1;   
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') 
            {
                dp[i] = 0;
                pfx[i] = pfx[i + 1];
                continue; 
            }
            ll num = 0;
            int j = i;
            for (; j < n; j++) {
                num = num * 10 + (s[j] - '0'); 
                if (num > k) break;  
            }
            if(j == n) 
                dp[i] = (pfx[i + 1] + 1) % MOD;
            else
                dp[i] = (pfx[i + 1] - pfx[j + 1] + MOD) % MOD; 
            pfx[i] = (pfx[i + 1] + dp[i]) % MOD;
        }
        return dp[0];  
    }
};