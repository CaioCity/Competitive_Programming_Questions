// https://leetcode.com/problems/longest-increasing-subsequence/description/
// 300 - Longest Increasing Subsequence (LIS)

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> ans(1);
        int tam=nums.size();
        ans[0]=nums[0];
        for(int i=1; i<tam; ++i){
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            if(it==ans.end())
                ans.push_back(nums[i]);
            else
                *it=nums[i];
        }
        return ans.size();
    }
};
