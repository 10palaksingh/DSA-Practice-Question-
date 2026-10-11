class Solution {
public:
    bool isValidSerialization(string s) {
        int n = s.size();
        stack<int> st;
        int i = 0;

        while (i < n) {

            // Found "#,#" on top, try to reduce "node,#,#" -> "#"
            if (s[i] == '#' && !st.empty() && st.top() == -1) {
                st.pop();                 // remove first '#'

                // No parent exists, invalid serialization
                if (st.empty()) return false;

                st.pop();                 // remove parent node
            }
            else {
                int k = 0;

                // Null node
                if (s[i] == '#') {
                    k = -1;
                    i += 2;               // skip "#,"
                }
                else {
                    // Parse multi-digit number
                    while (i < n && s[i] != ',') {
                        k = k * 10 + (s[i] - '0');
                        i++;
                    }
                    i++;                  // skip comma
                }

                st.push(k);
            }
        }

        // Entire tree must reduce to a single '#'
        return (st.size() == 1 && st.top() == -1);
    }
};