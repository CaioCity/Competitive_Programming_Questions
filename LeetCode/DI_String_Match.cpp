// https://leetcode.com/problems/di-string-match/description
// DI String Match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        int max=s.size(),min=0;
        vector<int> ans(s.size()+1);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='I')
                ans[i]=min++;
            else ans[i]=max--;
        }
        ans[s.size()]=min;
        return ans;
    }
};  
