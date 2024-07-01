// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// 4 - Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        std::vector<int> merge (n+m);
        int i,j;
        for(i=0,j=0; i<m && j<n;){
            if(nums1[i]>nums2[j]){
                merge[i+j]=nums2[j];
                ++j;
            }
            else {
                merge[i+j]=nums1[i];
                ++i;
            }
        }
        while(i<m)
            merge[i+j-1]=nums1[i++];
        while(j<n)
            merge[i+j-1]=nums2[j++];

        if((m+n)&1)
            return (double) merge[(n+m)/2];
        else
            return (merge[(n+m)/2] + merge[(n+m)/2 - 1])/2.0;
    }
};
