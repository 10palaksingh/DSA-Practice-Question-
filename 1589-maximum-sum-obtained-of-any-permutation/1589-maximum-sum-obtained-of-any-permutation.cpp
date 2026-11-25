class Solution {
public:
    int mod = (int)1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> vals(n+1, 0);
        
        for(int i = 0 ; i < requests.size() ; i++){
            vals[requests[i][0]]++;
            vals[requests[i][1] + 1]--;
        }

        for(int i = 1 ; i < vals.size() ; i++){
            vals[i] = (vals[i] + vals[i-1]);
        }

        sort(vals.begin(), vals.end(), greater<int>());
        sort(nums.begin(), nums.end(), greater<int>());

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = (((long long)vals[i]%mod * nums[i]%mod)%mod + ans) %mod;
        }
        return ans;
    }
};