class Solution {
public:
    int maximumScore(vector<int> const& nums, vector<int> const& multipliers) {
        const int N = nums.size();
        const int M = multipliers.size();

        vector<int> dp_prev(M + 1);

        vector<int> dp(M + 1);

        for (int i = 1; i <= M; ++i) {
            for (int j = 0; j <= i; ++j) {
                auto num_right = i - j;
                auto right_index = N - num_right;
                auto multiplier = multipliers[i - 1];

                auto write = INT_MIN;

                if (num_right > 0) {
                    write = dp_prev[j] + nums[right_index] * multiplier;
                }

                if (j > 0) {
                    write = max(write, dp_prev[j - 1] + nums[j - 1] * multiplier);
                }

                dp[j] = write;
            }

            std::swap(dp, dp_prev);
        }

        return *std::max_element(dp_prev.begin(), dp_prev.end());
    }
};