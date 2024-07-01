// https://leetcode.com/problems/three-consecutive-odds/description
// 1550 - Three Consecutive Odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int tam=arr.size();
        for(int i=2; i<tam; ++i)
            if( 1 & arr[i] && 1 & arr[i-1] && 1 & arr[i-2])
                return true;
        return false;
    }
};
