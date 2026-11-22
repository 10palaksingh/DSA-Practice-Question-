class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] % 2 == 0)
                sum += nums[i];
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][1];
            int val = queries[i][0];
            if ((nums[idx] + val) % 2 == 0 && nums[idx] % 2 == 0) {
                sum -= nums[idx];
                nums[idx] += val;
                sum += nums[idx];
                ans.push_back(sum);

            } else if ((nums[idx] + val) % 2 == 0 && nums[idx] % 2 != 0) {
                nums[idx] += val;
                sum += nums[idx];
                ans.push_back(sum);
            } else if ((nums[idx] + val) % 2 != 0 && nums[idx] % 2 == 0) {
                sum -= nums[idx];
                nums[idx] += val;
                ans.push_back(sum);
            } else if ((nums[idx] + val) % 2 != 0 && nums[idx] % 2 != 0) {
                nums[idx] += val;
                ans.push_back(sum);
            }
        }
        return ans;
    }
};