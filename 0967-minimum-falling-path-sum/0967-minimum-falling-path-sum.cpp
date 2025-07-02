class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();

        vector<int> dp = matrix[0]; 

        for (int i = 1; i < m; i++) {
            vector<int> next_dp(m, INT_MAX);

            for (int j = 0; j < m; j++) {
                int above = dp[j];

                int left = (j > 0) ? dp[j - 1] : INT_MAX;
                int right = (j < m - 1) ? dp[j + 1] : INT_MAX;

                next_dp[j] = matrix[i][j] + min({left, above, right});
            }

            dp = next_dp;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
