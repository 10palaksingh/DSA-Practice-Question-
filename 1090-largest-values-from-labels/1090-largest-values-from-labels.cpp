class Solution {
public:
static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int,int>mp;
        int n=values.size();
        int k=numWanted;
        int l=useLimit;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({values[i],labels[i]});
        }
        sort(p.begin(),p.end(),cmp);
        int max_sum=0;
        for(int i=0;i<n;i++){
             if(k>0 && mp[p[i].second]==0){
                max_sum+=p[i].first;
               // cout<<"max_sumone"<<max_sum<<endl;
                mp[p[i].second]++;
                k--;
             }
             else if(k>0 && mp[p[i].second]>0){
                if(mp[p[i].second]<useLimit){
                    max_sum+=p[i].first;
                    //cout<<"max_sumtwo"<<max_sum<<endl;
                    mp[p[i].second]++;
                    k--;
                }
                else{
                    continue;
                }
             }
             else{
                break;
             }
        }
        return max_sum;
    }
};