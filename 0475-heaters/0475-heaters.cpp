class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
     
        
        sort(heaters.begin(),heaters.end());
        int ans = INT_MIN;
        
        for(auto house : houses){
            
            auto it = lower_bound(heaters.begin(), heaters.end(),house);
            
            int right = INT_MAX;
            int left = INT_MAX;
            
     
            if(it != heaters.end()){
                right = *it - house;
            }
            
      
            if(it != heaters.begin()){
                it--;
                left = house - *it;
            }
            
            int nearest = min(right, left);
            ans = max(ans,nearest);
            
        }
        
        return ans;
        
    }
};