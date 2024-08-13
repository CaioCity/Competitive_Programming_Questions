// https://leetcode.com/problems/combination-sum-ii/description
// 40 - Combination Sum II

class Solution {
public:
    void explore (int index, int sum, int tam, int target, vector<int>& players, bool ativa[], vector<vector<int>>& ans){
        if(sum>target)
            return;
        if(sum==target){
            vector<int> aux;
            for(int i=0; i<index; ++i)
                if(ativa[i])
                    aux.push_back(players[i]);
            ans.push_back(aux);
            return;
        }    
        if(index==tam)
            return;
        
        ativa[index]=0;
        explore(index+1, sum, tam, target, players, ativa, ans);
        if(players[index-1]==players[index] && ativa[index-1]==0)
            return;
        ativa[index]=1;
        explore(index+1, sum+players[index], tam, target, players, ativa, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<int> players;
        bool exato=0;
        for(auto p : candidates){
            if(p==target)
                exato=1;
            if(p<target)
                players.push_back(p);
        }

        vector<vector<int>> ans;

        if(exato)
            ans.push_back(std::vector<int> (1,target));
        
        // sort(players.begin(), players.end(), greater<int>);
        sort(players.begin(), players.end());

        if(players.size()>0){
            bool ativa[players.size()];
            ativa[0]=0;
            explore(1, 0, players.size(), target, players, ativa, ans );
            ativa[0]=1;
            explore(1, players[0], players.size(), target, players, ativa, ans );
        }
        
        return ans;
    }
};
