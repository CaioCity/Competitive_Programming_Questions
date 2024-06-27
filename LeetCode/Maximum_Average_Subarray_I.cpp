// https://leetcode.com/problems/maximum-average-subarray-i/description
// Maximum Average Subarray I

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0,tam=nums.size(),max;
        for(int i=0; i<k; ++i)
            sum+=nums[i];
        max=sum;
        for(int i=1, j=k; j<tam; ++i, ++j){
            sum-=nums[i-1];
            sum+=nums[j];
            max=std::max(max,sum);
        }
        return (max*1.0)/k;
    }
};
