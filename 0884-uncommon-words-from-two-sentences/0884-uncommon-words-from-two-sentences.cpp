class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string word = s1 + " " + s2;

        unordered_map<string, int> map;
        string tmp = "";

        for (auto& ch : word) { 
            if (ch == ' ') { 
                if (!tmp.empty()) { 
                    map[tmp]++;
                    tmp = "";
                }
            } else {
                tmp += ch; 
            }
        }

        
        if (!tmp.empty()) {
            map[tmp]++;
        }

        
        vector<string> result;
        for (const auto& entry : map) {
            if (entry.second == 1) {
                result.push_back(entry.first); 
            }
        }

        return result;
    }
};