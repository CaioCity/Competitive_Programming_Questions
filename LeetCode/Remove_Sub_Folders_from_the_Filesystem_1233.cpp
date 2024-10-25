// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description
// 1233 - Remove Sub-Folders from the Filesystem

class Solution {
public:
    bool check (string& S, unordered_set<string>& hash){
        int tam = S.size();
        for(int i =1; i<tam; ++i)
            if(S[i]=='/' && hash.find(S.substr(0,i))!=hash.end())
                return 1;
        return 0;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        unordered_set<string> hash;
        sort(folder.begin(),folder.end());
        
        for(string& S : folder){
            if(check(S,hash))
                continue;
            hash.insert(S);
            ans.push_back(S);
        }
        return ans;
    }
};
