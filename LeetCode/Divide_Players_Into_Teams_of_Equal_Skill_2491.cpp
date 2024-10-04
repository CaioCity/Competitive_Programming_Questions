// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description
// 2491 - Divide Players Into Teams of Equal Skill

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int total, N = skill.size();
        int64_t sum = 0;
        sort(skill.begin(),skill.end());

        total = skill[0] + skill[N-1];

        for(int i=0; i< (N>>1); ++i)
            if( skill[i]+skill[N-i-1] == total)
                sum+=(skill[i] * skill[N-i-1]);
            else return -1;

        return sum;
    }   
};
