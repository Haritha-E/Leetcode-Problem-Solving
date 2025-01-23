class Solution {
public:
    bool ispredecessor(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();

        if (n - m != 1)
            return false;

        int i = 0, j = 0;

        while (i < m && j < n) {
            if (prev[i] == curr[j])
                i++;
            j++;
        }
        return i == m;
    }
    static bool comparator(string& word1, string& word2) {
        return word1.length() < word2.length();
    }

    int solve(vector<string>& words, int i, int prev, int dp[][1001]) {
        int take = 0;
        if (i >= words.size())
            return 0;

        if (prev != -1 && dp[i][prev] != -1)
            return dp[i][prev];

        int skip = solve(words, i + 1, prev, dp);

        if (prev == -1 || ispredecessor(words[prev], words[i]))
            take = 1 + solve(words, i + 1, i, dp);

        if (prev != -1)
            dp[i][prev] = max(skip, take);

        return max(skip, take);
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        int dp[1001][1001];

        memset(dp, -1, sizeof(dp));

        sort(begin(words), end(words), comparator);

        return solve(words, 0, -1, dp);
    }
};