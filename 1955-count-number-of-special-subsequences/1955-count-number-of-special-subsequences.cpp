class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        long long modValue = 1e9 + 7;
        long long dp[3] = {0, 0, 0};
       
        for (int i = 0; i < nums.size(); ++i)
        {
            switch (nums[i])
            {
            case 0:
            {
                dp[0] = (dp[0] + dp[0] + 1) % modValue;
                
                break;
            }
            case 1:
            {
                dp[1] = (dp[1] + dp[0] + dp[1]) % modValue;
             
                break;
            }
            case 2:
            {
                dp[2] = (dp[2] + dp[1] + dp[2]) % modValue;
                
                break;
            }
            }
        }
        return dp[2];
    }
};