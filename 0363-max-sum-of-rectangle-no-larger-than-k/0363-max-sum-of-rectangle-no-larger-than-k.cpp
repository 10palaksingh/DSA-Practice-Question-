class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int count = INT_MIN;
        for(int i = 0; i < matrix.size(); i++) {
            vector<int> prefix(matrix[0].size(), 0);
            for(int j = i; j < matrix.size(); j++) {
                for(int col = 0; col < matrix[0].size(); col++) {
                    prefix[col] += matrix[j][col];
                }
                map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int col = 0; col < matrix[0].size(); col++) {
                    sum += prefix[col];
                    auto it = mp.lower_bound(sum - k);
                    if(it != mp.end()) {
                        count = max(count, sum - it->first);
                    }
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};