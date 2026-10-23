class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        vector<int> s(n + 2, 0);
        s[0] = 1; s[1] = 2; s[2] = 2;
        int i = 2;
        int len = 3;
        while (len < n) {
            int val = 3 - s[len - 1];      
            int count = s[i];              
            for (int k = 0; k < count && len < n + 2; ++k) {
                s[len++] = val;
            }
            i++;
        }
        int ones = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 1) ones++;
        }
        return ones;
    }
};