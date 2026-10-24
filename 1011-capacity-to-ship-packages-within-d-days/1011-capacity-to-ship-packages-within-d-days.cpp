#include<bits/stdc++.h>
using namespace std;
int ReqDay(vector<int>& weights,int days,int capacity){
    int usedDay = 1;
    int currLoad= 0;
    for(int weg:weights){
        if(currLoad + weg > capacity){
            usedDay++;
            currLoad = weg;
        }
        else{
            currLoad += weg;
        }
    }
    return usedDay <=  days;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int answer = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(ReqDay(weights,days,mid)){
                answer = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return answer ;  
    }
};