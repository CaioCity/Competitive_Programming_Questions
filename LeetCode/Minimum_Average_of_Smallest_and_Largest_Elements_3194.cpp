// https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/
// 3194 - Minimum Average of Smallest and Largest Elements

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double menor=INT32_MAX;
        std::sort(nums.begin(),nums.end());
        for(int i=0,j=nums.size()-1; i<j; ++i,--j)
            menor=std::min(menor, (nums[i]+nums[j])/2.0 );
        return menor;
    }
};
