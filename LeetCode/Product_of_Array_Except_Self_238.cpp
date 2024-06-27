// https://leetcode.com/problems/product-of-array-except-self/description
// 238 - Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tam=nums.size();
        vector<int> prefix(tam), suffix(tam), ans(tam);
        prefix[0]=nums[0];
        for(int i=1; i<tam; ++i)
            prefix[i]=nums[i]*prefix[i-1];
        suffix[tam-1]=nums[tam-1];
        for(int i=tam-2; i>=0; --i)
            suffix[i]=suffix[i+1]*nums[i];
        
        ans[0]=suffix[1];
        ans[tam-1]=prefix[tam-2];
        for(int i=1; i<(tam-1); ++i)
            ans[i]=prefix[i-1]*suffix[i+1];
        return ans;
    }
};
