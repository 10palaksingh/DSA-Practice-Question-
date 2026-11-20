class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return false;

        int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        int n = grid.size(), k = 0;
        int cr = 0, cc = 0;

        while (k < n * n - 1) {
            bool found = false;

            for (int i = 0; i < 8; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == k + 1) {
                    k++;
                    found = true;
                    cr = nr;
                    cc = nc;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }
};