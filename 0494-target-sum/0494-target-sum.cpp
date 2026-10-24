class Solution {
public:
    void targetSum(vector<int>& nums, int index, int& count, int& sum,
                   int& target) {
    
        if (index == nums.size()) {
            if (sum == target)
                count++;
            return;
        }
  
        sum += nums[index];
        targetSum(nums, index + 1, count, sum, target);
        sum -= nums[index];

    
        sum -= nums[index];
        targetSum(nums, index + 1, count, sum, target);
        sum += nums[index];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int sum = 0;
        targetSum(nums, 0, count, sum, target);
        return count;
    }
};