#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int bestRotation(std::vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> change(n, 0);

        for (int i = 0; i < n; ++i) {
            int loss_k = (i - nums[i] + 1 + n) % n;
            int gain_k = (i + 1) % n;

            change[loss_k]--;
            change[gain_k]++;
        }

        int max_score = 0;
        int current_score = 0;
        int best_k = 0;

        for (int k = 1; k < n; ++k) {
            current_score += change[k];
            if (current_score > max_score) {
                max_score = current_score;
                best_k = k;
            }
        }

        return best_k;
    }
};