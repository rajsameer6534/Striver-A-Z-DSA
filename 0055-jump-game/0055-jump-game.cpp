class Solution {
public:
    vector<int>dp;
    bool helper(int idx,vector<int>&arr){
        if(idx>=arr.size()-1) return true;
        if(dp[idx]!=-1) return dp[idx];
        bool ans =false;
        if(arr[idx]>=arr.size()-1-idx) return true;
        for(int i=1;i<=arr[idx];i++){
            ans=ans||helper(idx+i,arr);
            if(ans) break;
        }
        return dp[idx]=ans;
    }
    bool canJump(vector<int>& arr) {
        dp.resize(arr.size(),-1);
        return helper(0,arr);
    }
};