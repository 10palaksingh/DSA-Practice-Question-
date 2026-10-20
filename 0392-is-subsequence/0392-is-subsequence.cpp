class Solution {
public:
    bool check(string& s, string& t, int i, int j) {

        if (i == s.length()) {
            return true;
        }

        if (j == t.length()) {
            return false;
        }

        if (s[i] == t[j]) {
            return check(s, t, i + 1, j + 1);
        }

        return check(s, t, i, j + 1);
    }

    bool isSubsequence(string s, string t) {
        return check(s, t, 0, 0);
    }
};