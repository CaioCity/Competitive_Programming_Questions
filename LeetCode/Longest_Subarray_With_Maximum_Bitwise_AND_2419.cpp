// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
// 2419 - Longest Subarray With Maximum Bitwise AND

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size(),rep,max=nums[0],maxrep=0;
        
        for(int i=1; i<N; ++i)
            if(nums[i]>max)
                max = nums[i];

        for(int i=0; i<N; ++i)
            if(nums[i]==max){
                for(rep=1; i+1<N && nums[i]==nums[i+1]; ++i)
                    ++rep;
                maxrep = std::max(maxrep,rep);
            }

        return maxrep;
    }
};
