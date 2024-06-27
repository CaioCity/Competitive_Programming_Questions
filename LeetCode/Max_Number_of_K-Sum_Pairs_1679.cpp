// https://leetcode.com/problems/max-number-of-k-sum-pairs/description
// 1679 - Max Number of K-Sum Pairs

// Two Pointers
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0,sum;
        std::sort(nums.begin(),nums.end());
        for(int i=0, j=nums.size()-1; i<j; ){
            sum=nums[i]+nums[j];
            if(sum>k)
                --j;
            else if(sum<k)
                ++i;
            else {
                ++i; --j;
                ++ans;
            }
        }
        return ans;
    }
};

// Hash Map
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> sum;
        for(auto i : nums){
            if(sum[k-i]!=0){
                ++ans;
                --sum[k-i];
            }
            else sum[i]++;
        }
        return ans;
    }
};
