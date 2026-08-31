class Solution {
public:
    int f(int idx, int sum ,vector<int>& nums,  vector<vector<int>>&dp ){
        if(idx==0){
            if(sum==0 && nums[0]==0) return 2;
            if(sum==0 || sum==nums[0]) return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int notTake = f(idx-1, sum, nums, dp);
        int take = 0;
        if(nums[idx] <= sum) take = f(idx-1, sum - nums[idx], nums, dp);
        return dp[idx][sum] = notTake + take;
    }

    int findways(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if(totSum - target < 0 || (totSum - target) % 2 != 0) return 0;
        return findways(nums, (totSum - target) / 2);
    }
};
