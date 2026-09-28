class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        set<int>st;
        for(int x : nums){
            st.insert(x);
        }
        if(st.size() >=  3 ){
            auto it = st.rbegin();
            advance(it,2);
            return *it;
        
        } 
        else {
            return *st.rbegin();
        }

      
    }
};