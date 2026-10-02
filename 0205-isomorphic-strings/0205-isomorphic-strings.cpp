class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, char> charMapping;
        unordered_set<char> usedReplacements;

        for(int i = 0; i < s.length(); i++) {
            char original = s[i];
            char replacement = t[i];

            // Create a new mapping
            if(charMapping.find(original) == charMapping.end()) {

                // Replacement is already mapped to another character
                if(usedReplacements.count(replacement))
                    return false;

                charMapping[original] = replacement;
                usedReplacements.insert(replacement);
            }

            // Existing mapping must remain consistent
            else if(charMapping[original] != replacement) {
                return false;
            }
        }

        return true;
    }
};