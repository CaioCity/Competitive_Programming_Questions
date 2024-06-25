// https://leetcode.com/problems/most-profit-assigning-work/description/
// Most Profit Assigning Work

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int tam=difficulty.size(),ans=0;
        vector<pair<int,int>> V (tam);
        for(int i=0; i<tam; i++)
            V.push_back({profit[i],-1*difficulty[i]});
        sort(V.begin(),V.end(),std::greater<pair<int,int>>());

        for(auto i : worker){
            int index=0;
            while((-1*V[index].second)>i)
                index++;
            if(index!=tam)
                ans+=V[index].first;
        }
        return ans;
    }
};
