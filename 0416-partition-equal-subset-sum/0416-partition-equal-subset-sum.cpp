class Solution {
public:
    bool solve(vector<int>& nums,int idx,int capacity, vector<vector<int>>&dp){
        if(idx==0) return nums[idx]==capacity;
        if(capacity==0) return true;
        if(capacity<0) return false;
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        
        bool a=false;
        if(nums[idx]<=capacity)  a=solve(nums,idx-1,capacity-nums[idx],dp);
        bool b=solve(nums,idx-1,capacity,dp);
        return dp[idx][capacity]=a||b;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        sum=sum/2;
       vector<vector<int>>dp(n,vector<int>(sum+1,-1));
       return solve(nums,n-1,sum,dp);
    }
};