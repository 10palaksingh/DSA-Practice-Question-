class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if(boardingCost * 4 <= runningCost) return -1;
        int wait = 0, prof = 0, maxprof = 0, maxrot = -1;
        for(int rot = 0, n = customers.size(); rot < n || wait; ++rot){
            if(rot < n) wait += customers[rot];
            prof += min(wait , 4) * boardingCost - runningCost;
            wait -= min(wait , 4);
            if(maxprof < prof){
                maxprof = prof;
                maxrot = rot + 1;
            }
        }
        return maxrot;
    }
};