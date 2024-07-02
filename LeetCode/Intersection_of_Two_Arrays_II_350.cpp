// https://leetcode.com/problems/intersection-of-two-arrays-ii/description
// 350 - Intersection of Two Arrays II

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(),nums1.end());
        std::sort(nums2.begin(),nums2.end());
        int tam1=nums1.size(), tam2=nums2.size();
        vector<int> ans;
        for( int i=0,j=0; i<tam1 && j<tam2; ){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                ++i; ++j;
            }
            else if(nums1[i]<nums2[j])
                ++i;
            else ++j;            
        }
        return ans;
    }
};
