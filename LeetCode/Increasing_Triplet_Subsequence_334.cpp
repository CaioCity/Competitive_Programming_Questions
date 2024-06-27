// https://leetcode.com/problems/increasing-triplet-subsequence/description
// 334 - Increasing Triplet Subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int menor=nums[0], menor2=INT32_MAX, menorpos=INT32_MAX, tam=nums.size();
        for(int i=1; i<tam; ++i){
            if(nums[i]>menor2)
                return 1;
            if(nums[i]>menor && nums[i]<menor2)
                menor2=nums[i];
            if(nums[i]<menorpos && menor>nums[i])
                menorpos=nums[i];
            if(nums[i]>menorpos && nums[i]<menor2){
                menor2=nums[i];
                menor=nums[i];
            }
        }
        return 0;
    }
};
