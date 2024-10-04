// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
// 974 - Subarray Sums Divisible by K

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int mod, N = nums.size(), ans = 0, prefix = 0;
        unordered_map<int,int> hashmap;
        for(int i=0; i<N; ++i){
            prefix+=nums[i];
            mod = ((prefix%k) + k)%k;
            if(mod==0)
                ++ans;
            ans+=hashmap[mod];
            ++hashmap[mod];
        }
        return ans;
    }
};
