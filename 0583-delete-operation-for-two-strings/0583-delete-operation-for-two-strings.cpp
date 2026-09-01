class Solution {
public:
     vector<vector<int>>dp;
    int f(string &s1,string &s2,int i,int j){
        if(i>=s1.size()) return 0;
        if(j>=s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j]=max(f(s1,s2,i+1,j),f(s1,s2,i,j+1));
        }
    }
    int minDistance(string word1, string word2) {
        dp.clear();
        dp.resize(1005,vector<int>(1005,-1));
        int ans=f(word1,word2,0,0);
        int count=0;
        int x=word1.size()-ans;
        int y=word2.size()-ans;
        return x+y;
    }
};