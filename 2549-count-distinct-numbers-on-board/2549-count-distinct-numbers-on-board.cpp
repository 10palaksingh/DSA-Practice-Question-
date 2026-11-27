class Solution {
public:
    unordered_set<int> s;
    int distinctIntegers(int n) {
        if(n==1 || n==2) return 1;
        return n-1;
      
    }
};