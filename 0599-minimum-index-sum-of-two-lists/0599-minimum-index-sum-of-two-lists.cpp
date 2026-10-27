class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        std::vector<std::string>ans;
        std::unordered_map<std::string,int>map;
        map.reserve(list1.size());
        int minSum  =INT_MAX;
        for(int i =0 ;i<list1.size();++i){
            map.insert({list1[i],i});
        }
        for(int i =0;i<list2.size();++i){
            if(map.contains(list2[i])){
                if(minSum>i+map.at(list2[i])){
                    ans.clear();
                    ans.push_back(list2[i]);
                    minSum= i+map.at(list2[i]);
                }
                else if(minSum == map.at(list2[i])+i){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
        
    }
};