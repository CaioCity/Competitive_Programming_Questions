// https://leetcode.com/problems/find-the-highest-altitude/description
// 1732 - Find the Highest Altitude

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0, ans=0, tam=gain.size();
        for(int i=0; i<tam; ++i){
            sum+=gain[i];
            ans=std::max(ans,sum);
        }
        return ans;
    }
};
