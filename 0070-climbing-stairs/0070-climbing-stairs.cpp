class Solution {
public:
    int f(int idx,vector<int>&dp){
        if(idx==0) return 1;
        if(idx==1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        int s1=f(idx-1,dp);
        int s2=f(idx-2,dp);
        return dp[idx]=s1+s2;

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);

        return f(n,dp);
    }
};