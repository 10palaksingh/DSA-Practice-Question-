#include<bits/stdc++.h>
using namespace  std;
int divisor(vector<int>&nums,int div){
    int n = nums.size();
    int sum=0;
    for(int i =0;i<n;i++){
        sum = sum + ceil((double)(nums[i])/(double)div);

    }
    return sum;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = low + (high-low)/2;
            if(divisor(nums,mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};