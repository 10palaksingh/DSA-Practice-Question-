class Solution {
public:
    int trailingZeroes(int n) {
        long ans = 0;
        while(n>0){
            n = n/5;
            ans = ans + n;
        }
        return ans;
    }
};