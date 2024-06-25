// https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Find Minimum Operations to Make All Elements Divisible by Three

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for(int i : nums)
            if(i%3)
                ans++;
        return ans;
    }
};
