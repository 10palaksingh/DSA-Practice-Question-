class Solution {
public:
    int videoStitching(vector<vector<int>>&nums,int t){

        int n=nums.size();

        sort(nums.begin(),nums.end());

        int i=0;
        while(i<n-1 && nums[i][0]==nums[i+1][0]){
            i++;
        }

        int prevStart=nums[i][0];
        int prevEnd=nums[i][1];
        if(prevStart!=0) return -1;
        int ans=1;
        i++;

        while(i<n){

            if(prevEnd>=t) return ans;

            int maxEnd=nums[i][1];
            bool flag=false;
            while(i<n && nums[i][0]<=prevEnd){
                flag=true;
                maxEnd=max(nums[i][1],maxEnd);
                i++;
            } 
            if(flag) i--;

            if(nums[i][0]>prevEnd) break;
            prevEnd=maxEnd;
            ans++;

            i++;

        }

        if(prevEnd>=t) return ans;
        return -1;
        
    }
};


