class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        int n1=f.size();
        int n2=s.size();
        while (i<n1 && j<n2){
            int st=max(f[i][0],s[j][0]);
            int en=min(f[i][1],s[j][1]);
            if(st<=en) ans.push_back({st,en});
            if (f[i][1]<s[j][1]) i+=1;
            else j+=1;
        

        }
        
        return ans;

    }
};