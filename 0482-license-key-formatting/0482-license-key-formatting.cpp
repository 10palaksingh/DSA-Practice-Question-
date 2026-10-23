class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        std::string ans;
        int charsAdded=0;
        for(int i=s.length()-1;i>=0;i--){
            s[i]=std::toupper(s[i]);
            if(s[i]!='-'){
                ans+=s[i];
                charsAdded++;
            }
            if(charsAdded==k){
                ans+='-';
                charsAdded=0;
            }
        }
        while(!ans.empty()&&ans.back()=='-'){
            ans.pop_back();
        }
        ans.shrink_to_fit();
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};