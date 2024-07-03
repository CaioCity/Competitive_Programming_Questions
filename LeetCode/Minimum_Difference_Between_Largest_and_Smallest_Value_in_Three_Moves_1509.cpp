// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description
// 1509 - Minimum Difference Between Largest and Smallest Value in Three Moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int tam=nums.size(), begin=0, end=0, ans=INT32_MAX;

        if(tam<=4) return 0;

        std::sort(nums.begin(),nums.end());

        if(nums[0]==nums[tam-1]) return 0;

        ans=min(ans, nums[tam-4]-nums[0]);
        ans=min(ans, nums[tam-3]-nums[1]);
        ans=min(ans, nums[tam-2]-nums[2]);
        ans=min(ans, nums[tam-1]-nums[3]);
            
       return ans;
    }
};
