#include<bits/stdc++.h>
using namespace std;
int canMakeBow(vector<int>&bloomDay,int m ,int k,int day){
   
    int consequtive =0;
    int bow= 0;
    for(int bloom: bloomDay){
        if(bloom <=day){
            consequtive++;
                if(consequtive == k){
                    bow++;
                    consequtive = 0;
                }
        }
        else{
            consequtive =0;
        }
        
    }
    return bow >= m;
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int n = bloomDay.size();
        int answer  =-1;
        if((long long )m*k > n) return -1;
        while(low<= high){
            int mid = low + (high -low)/2;
            if(canMakeBow(bloomDay, m , k ,mid)){
                answer = mid;
                high =mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return answer;
        
    }
};