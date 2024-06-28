// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description
// 1493 - Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0, next, max=0, tam=nums.size();

        while(j<tam && nums[j++]);
        std::cout<<"j = "<<j<<'\n';

        if(j==tam) return (tam-1);
        next=j;
        while(j<tam){
            if(!nums[j]){
                std::cout<<"j = "<<j<<" i = "<<i<<'\n';
                std::max(max,j-i);
                i=next;
                next=j;
            }
            ++j;
        }
        if(i==0)
            return tam-1;
        std::cout<<" i == "<<i<<'\n';
        // while(i<j && !nums[i++]);
        return std::max(max,tam-i);
    }
};
