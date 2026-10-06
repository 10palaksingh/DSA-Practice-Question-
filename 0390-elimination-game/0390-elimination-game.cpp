class Solution {
public:
    int lastRemaining(int n, bool left = true, int dis = 1) {

        if (n == 1)
            return 1; 
        
        if (left || n % 2 == 1) 
            return dis + lastRemaining(n / 2, !left, dis * 2);
        
        return lastRemaining(n / 2, !left, dis * 2);
    }
};