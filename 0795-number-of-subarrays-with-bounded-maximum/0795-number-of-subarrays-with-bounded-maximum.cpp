class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int si=0;
        int ei=0;
        int ans=0;
        int precount=0;
        while(ei<n){
            if(left<=nums[ei] && nums[ei]<=right){
                precount=ei-si+1;
                ans+=precount;
            }else if(left>nums[ei]){
                ans+=precount;
            }else{
                si=ei+1;
                precount=0;
            }
            ei++;
        }
        return ans;
    }
};