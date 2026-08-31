class Solution {
public:
    int f(int i, int j, vector<vector<int>>& Grid, vector<vector<int>>& dp) {
        if (i >= 0 && j >= 0 && Grid[i][j] == 1) return 0;  // obstacle
        if (i == 0 && j == 0) return 1;                     // start
        if (i < 0 || j < 0) return 0;                       // out of bounds
        if (dp[i][j] != -1) return dp[i][j];                // memo

        int up = f(i - 1, j, Grid, dp);
        int left = f(i, j - 1, Grid, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size();        // rows
        int m = Grid[0].size();     // columns

        // ✅ Correct dimension
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // ✅ Special case: if start cell is an obstacle
        if (Grid[0][0] == 1) return 0;

        return f(n - 1, m - 1, Grid, dp);
    }
};
