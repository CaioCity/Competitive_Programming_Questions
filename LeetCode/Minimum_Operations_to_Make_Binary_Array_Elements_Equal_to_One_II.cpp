// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
// Minimum Operations to Make Binary Array Elements Equal to One II

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0, tam=nums.size();
        for(int i=0; i<tam; ++i)
            if(!(((int)nums[i] + ans)&1))
                ++ans;
        return ans;
    }
};
