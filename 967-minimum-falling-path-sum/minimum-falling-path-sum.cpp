class Solution {
private:
    int minPathSum(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& memo) {
        //cout << "i:" << i << " j:" << j << endl;
        int sum = matrix[i][j];
        if (i == (matrix.size() - 1)) {
            return sum;
        }
        int leftSum = INT_MAX;
        int centerSum = INT_MAX;
        int rightSum = INT_MAX;
        if (memo[i][j] < INT_MAX) return memo[i][j];
        if (j > 0) {
            leftSum = minPathSum(matrix, i+1, j-1, memo);
        }
        centerSum = minPathSum(matrix, i+1, j, memo);
        if (j < matrix.size()-1) {
            rightSum = minPathSum(matrix, i+1, j+1, memo);
        }
        sum += min(leftSum, min(centerSum, rightSum));
        //cout << "Sum:" << sum << endl;
        memo[i][j] = sum;
        return sum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minSum = INT_MAX;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix.size(), INT_MAX));
        for (int i = 0; i < matrix.size(); i++) {
            int sum = minPathSum(matrix, 0, i, memo);
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};