// https://leetcode.com/problems/longest-square-streak-in-an-array/description/
// 2501 - Longest Square Streak in an Array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        set<int64_t> hash;

        int count = 1, max = 1;

        for(int x : nums)
            hash.insert(x*1ll);

        for(int64_t x : hash){
            x*=x;
            while(hash.find(x)!=hash.end()){
                hash.erase(x);
                ++count;
                x*=x;
            }
            max = max<count? count : max;
            count = 1;
        }

        return max==1? -1 : max;        
    }
};
