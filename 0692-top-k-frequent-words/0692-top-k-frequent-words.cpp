struct Compare {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b){    
            if(a.first==b.first){
                return a.second<b.second; //priority given to b over a
            } else {
                return a.first>b.first;
            }
        }
    };

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

        for(string w:words){
            m[w]++;
        }

        for(auto &[w, i]:m){
            pq.push({i, w});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};