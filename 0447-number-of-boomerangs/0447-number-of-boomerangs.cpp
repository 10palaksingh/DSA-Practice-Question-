class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
    unordered_map<int, int> distances;
    int num_boomerangs = 0;
    
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
            if (distances.find(distance) == distances.end()) {
                distances[distance] = 1;
            }
            else {
                distances[distance]++;
            }
        }
        for (auto val : distances) {
            num_boomerangs += val.second * (val.second - 1);
        }
        distances.clear();
    }
    
    return num_boomerangs;
    }
};