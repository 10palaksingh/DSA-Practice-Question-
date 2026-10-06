class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(string& s, string& reversed, int i, int j) {
        if (i >= n || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == reversed[j]) {
            int take = 1 + solve(s, reversed, i + 1, j + 1);
            return dp[i][j] = take;
        } else {
            int skipI = solve(s, reversed, i + 1, j);
            int skipJ = solve(s, reversed, i, j + 1);
            return dp[i][j] = max(skipI, skipJ);
        }
    }

    int longestPalindromeSubseq(string s) {
        n = s.size();

        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        dp.assign(n, vector<int>(n, -1));

        return solve(s, reversed, 0, 0);
    }
};