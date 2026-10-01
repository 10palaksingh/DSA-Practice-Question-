class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();

        for (int i = 0; i < n;) {
            int start = i;

            while (i < n && title[i] != ' ')
                i++;

            int len = i - start;

            for (int j = start; j < i; j++)
                title[j] = tolower(title[j]);

            if (len >= 3)
                title[start] = toupper(title[start]);

            i++;
        }

        return title;
    }
};