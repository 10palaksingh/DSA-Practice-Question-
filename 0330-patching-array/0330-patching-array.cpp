class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int count = 0;

        int x = nums.size();

        for (int i = 0; i < x; i++) {
            if (sum >= n)
                break;

            if (nums[i] > sum + 1) {
                count++;
                sum = sum + sum + 1;
                i--;
            }
            else {
                sum += nums[i];
            }
        }

        while (sum < n) {
            sum = sum + sum + 1;
            count++;
        }

        return count;
    }
};