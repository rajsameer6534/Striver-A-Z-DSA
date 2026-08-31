class Solution {
public:
    int f(int i, int tar,vector<int>& coins,vector<vector<int>>&dp ){
        // base n-1--------->0
        // [4] tar=4 ok
        // [3] tar=4 not ok
        // [2] tar=4 ok as [2,2]
        // this means if(tar%coins[i]) then we can take return 1;
        if(i==0){
            if(tar%coins[0]==0) return 1;
            return 0;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        int notTake=f(i-1, tar, coins,dp);
        int take=0;
        if(coins[i]<=tar) take=f(i,tar-coins[i],coins,dp);
        return dp[i][tar]=notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};