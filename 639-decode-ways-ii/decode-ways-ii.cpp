class Solution {
public:
    vector<int>dp;
    int fnc(int i, string&s) {
        if(i==s.size())return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        long long op1=0,op2=0; // Use long long to handle large calculations
        if(s[i]=='*') {
            op1=(9LL*fnc(i+1,s))%1000000007; // Explicitly use long long
            if(i+1<s.size()) {
                if(s[i+1]!='*') {
                    if(s[i+1]<='6')op2=(2LL*fnc(i+2,s))%1000000007;
                    else op2=fnc(i+2,s)%1000000007;
                } else {
                    op2=(15LL*fnc(i+2,s))%1000000007;
                }
            }
        } else {
            op1=fnc(i+1,s)%1000000007;
            if(i+1<s.size()&&s[i+1]!='*'&&stoi(s.substr(i,2))<=26)op2=fnc(i+2,s)%1000000007;
            else if(i+1<s.size()&&s[i+1]=='*') {
                if(s[i]=='1')op2=(9LL*fnc(i+2,s))%1000000007;
                else if(s[i]=='2')op2=(6LL*fnc(i+2,s))%1000000007;
            }
        }
        return dp[i]=(op1+op2)%1000000007;
    }
    int numDecodings(string s) {
        dp.resize(s.size()+1,-1);
        if(s.empty()||s[0]=='0')return 0;
        return fnc(0,s);
    }
};