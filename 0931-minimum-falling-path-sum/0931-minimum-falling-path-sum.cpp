class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row is same
        for(int j = 0; j < m; j++)
            dp[0][j] = mat[0][j];

        // Build DP table
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int up = dp[i-1][j];
                int ldia = (j > 0) ? dp[i-1][j-1] : 1e9;
                int rdia = (j < m-1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = mat[i][j] + min(up, min(ldia, rdia));
            }
        }

        // Minimum in last row
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
