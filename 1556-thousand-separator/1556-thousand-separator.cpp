class Solution {
public:
    string thousandSeparator(int n) {
        if(n == 0)
        return "0";
        string ans = "";
        int count = 0;

        while(count != 3 &&n != 0){
            int rem = n % 10; 
            ans += rem + '0'; 
            n /= 10; 
            count++;

            if(count % 3 == 0 && n != 0){
                ans += ".";
                count = 0;
            }
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};