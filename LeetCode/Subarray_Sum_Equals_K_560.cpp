// https://leetcode.com/problems/subarray-sum-equals-k/
// 560 - Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size(), ans = 0, prefix = 0;
        unordered_map<int,int> hashmap;
        for(int i=0; i<N; ++i){
            prefix+=nums[i];
            if(prefix==k)
                ++ans;
            if(hashmap[prefix-k]!=0)
                ans+=hashmap[prefix-k];
            ++hashmap[prefix];
        }
        return ans;
    }
};
