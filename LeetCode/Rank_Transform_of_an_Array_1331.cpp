// https://leetcode.com/problems/rank-transform-of-an-array
// 1331 - Rank Transform of an Array

class Solution {
public:
    int my_binary_search(int target, int begin, int end,vector<int>& rank){
        if(end-begin < 2){
            if(target == rank[end])
                return end;
            else return begin;
        }

        int mid = (begin+end)>>1;

        if(target == rank[mid])
            return mid;
        if(target < rank[mid])
            return my_binary_search(target, begin, mid-1, rank);
    //  if(target > rank[mid])
            return my_binary_search(target, mid+1, end, rank);
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
        vector<int> rank (arr.begin(), arr.end()), ans(N);

        sort(rank.begin(),rank.end());
        vector<int>::iterator it = unique(rank.begin(),rank.end());
        rank.erase(it, rank.end());

        for(int i=0; i<N; ++i)
            ans[i] = my_binary_search(arr[i], 0, rank.size()-1, rank) + 1;

        return ans;
    }
};
