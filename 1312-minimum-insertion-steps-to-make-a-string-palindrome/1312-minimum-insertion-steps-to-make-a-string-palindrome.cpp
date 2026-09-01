class Solution {
public:
    vector<vector<int>> dp;
    string ans = "";

    int f(string &s1, string &s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(s1, s2, i + 1, j + 1);
        } else {
            return dp[i][j] = max(f(s1, s2, i, j + 1), f(s1, s2, i + 1, j));
        }
    }

    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        int n = s1.size();
        dp.assign(n, vector<int>(n, -1));

        f(s1, s2, 0, 0);

        int i = 0, j = 0;
        ans = "";
        while (i < n && j < n) {
            if (s1[i] == s2[j]) {
                ans += s1[i];
                i++, j++;
            } 
            else if (j + 1 < n && dp[i][j + 1] >= (i + 1 < n ? dp[i + 1][j] : -1)) {
                j++;
            } 
            else if (i + 1 < n) {
                i++;
            } 
            else {
                break;
            }
        }
        
        return n-ans.size();
    }
};