// https://leetcode.com/problems/grumpy-bookstore-owner/description/
// 1052 - Grumpy Bookstore Owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int max,tam=customers.size(),ans=0;
        vector<int> prefix(tam);
        if(grumpy[0])
            prefix[0]=customers[0];
        else{
            prefix[0]=0;
             ans=customers[0];
        }
        for(int i=1; i<tam; i++){
            prefix[i]=prefix[i-1];
            if(grumpy[i])
                prefix[i]+= customers[i];
            else ans+=customers[i];
        }
        max=prefix[minutes-1];
        for(int j=minutes, i=1; j<tam; i++,j++){
            max=std::max(max,prefix[j]-prefix[i-1]);
        }
        return max+ans;
    }
};
