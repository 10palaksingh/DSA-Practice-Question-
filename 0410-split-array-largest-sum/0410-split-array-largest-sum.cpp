class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        auto pieces = [&](int limit) {
            int count = 1, sum = 0;
            for (int x : nums) {
                if (sum + x > limit) { ++count; sum = x; }
                else sum += x;
            }
            return count;
        };
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (pieces(mid) > k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};