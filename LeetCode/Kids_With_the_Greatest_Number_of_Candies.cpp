// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Kids With the Greatest Number of Candies

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int g=0;
        vector<bool> ans(candies.size());
        for(auto i : candies)
            if(i>g)
                g=i;
        for(int i=0; i<candies.size(); i++)
            ans[i]= ((candies[i]+extraCandies)>=g ? 1 : 0);
        return ans;
    }
};
