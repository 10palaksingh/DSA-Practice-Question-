#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = size(nums);
        auto find_valleys = [&](int mode) {
            int res = 0;
            for (int i=0; i<n; i++) {
                if (i % 2 == mode) {
                    int left = (i-1 >= 0) ? nums[i-1] : INT_MAX;
                    int right = (i+1 < n) ? nums[i+1] : INT_MAX;
                    int min_neighbor = min(left, right);
                    if (nums[i] >= min_neighbor) {
                        res += nums[i] - (min_neighbor - 1);
                    }

                }
            }
            return res;
        };
        return min(find_valleys(0), find_valleys(1));
    }
};