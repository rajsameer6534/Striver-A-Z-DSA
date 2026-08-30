class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        int dp[n];
        //0 to n-2 index tk
        if(n==1) return arr[0];
        dp[0]=arr[0];
        if(n!=1) dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        }
        int max1=dp[n-2];
         //1 to n-1 index tk
        dp[1]=arr[1];
        if(n!=2) dp[2]=max(arr[1],arr[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
        }
        int max2=dp[n-1];
        return max(max1,max2);
    }
};