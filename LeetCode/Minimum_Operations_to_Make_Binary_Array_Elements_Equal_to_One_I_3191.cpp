// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
// 3191 - Minimum Operations to Make Binary Array Elements Equal to One I

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int loop=nums.size()-2,ans=0;
    
        for(int i=0; i<loop; ++i)
            if(!nums[i]){
                nums[i] = 1;
                nums[i+1] = nums[i+1]? 0 : 1;
                nums[i+2] = nums[i+2]? 0 : 1;
                ++ans;
            }

        if(!nums[loop] || !nums[loop+1])
            return -1;
        return ans;
    }
};
