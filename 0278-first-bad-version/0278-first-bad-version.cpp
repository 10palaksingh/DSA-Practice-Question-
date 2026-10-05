// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
using namespace std;

class Solution {
public:
    int binary_search(int n) {

        if (n == 1 && isBadVersion(n)) {
            return n;
        }

        int begin = 1;
        int end = n;

        while (begin < end) {
            int middle = begin + (end - begin) / 2;

            if (isBadVersion(middle)) {
                end = middle;
            }
            else {
                begin = middle + 1;
            }
        }
        return begin;
    }
    int firstBadVersion(int n) {
        return binary_search(n);
    }
};