

class Solution {
public:
    int f(int i, int j,vector<vector<int>>& grid, vector<vector<int>>&dp){
        // base case
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9; // out of bound
        if(dp[i][j]!=-1) return dp[i][j];
        int up=grid[i][j]+f(i-1,j,grid,dp);
        int down= grid[i][j]+ f(i,j-1,grid,dp);
        return dp[i][j]=min(up,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(); // row
        int n=grid[0].size(); // col
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1)); //dp intialized
        return f(m-1,n-1,grid, dp);
        
    }
};