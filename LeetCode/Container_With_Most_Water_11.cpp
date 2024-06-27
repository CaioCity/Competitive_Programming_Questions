// https://leetcode.com/problems/container-with-most-water/description
// 11 - Container With Most Water

class Solution {
public:
    int area (int a, int b, vector<int>& h){
        return (b-a)*std::min(h[a],h[b]);
    }
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,max=0;
        for(; left<right; ){
            max=std::max(max,(right-left)*std::min(height[left],height[right]));
            if(height[left]<height[right])
                ++left;
            else --right;
        }
        return max;
    }
};
