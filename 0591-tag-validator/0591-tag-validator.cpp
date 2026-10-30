#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> tags;
        int i = 0;
        int n = code.size();

        while (i < n) {
            if (i > 0 && tags.empty()) {
                return false;
            }

            if (code.substr(i, 9) == "<![CDATA[") {
                i += 9;
                while (i <= n - 3 && code.substr(i, 3) != "]]>") {
                    i++;
                }
                if (i > n - 3) return false; 
                i += 3; 
            }
            else if (code.substr(i, 2) == "</") {
                i += 2;
                int end = code.find('>', i);
                if (end == string::npos) return false;
                string tagName = code.substr(i, end - i);
                if (tagName.empty() || tagName.size() > 9) return false;
                for (char c : tagName) {
                    if (!isupper(c)) return false;
                }
                if (tags.empty() || tags.top() != tagName) return false;
                tags.pop();
                i = end + 1;
            }
            else if (code[i] == '<') {
                // Opening tag
                i++;
                int end = code.find('>', i);
                if (end == string::npos) return false;
                string tagName = code.substr(i, end - i);
                if (tagName.empty() || tagName.size() > 9) return false;
                for (char c : tagName) {
                    if (!isupper(c)) return false;
                }
                tags.push(tagName);
                i = end + 1;
            }
            else {
                i++;
            }
        }

        return tags.empty();
    }
};