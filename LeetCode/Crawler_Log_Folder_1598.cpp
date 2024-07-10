// https://leetcode.com/problems/crawler-log-folder/description
// 1598 - Crawler Log Folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(int i = 0, tam=logs.size(); i<tam; ++i){
            if(logs[i]=="../")
                ans = ans==0? 0 : --ans;
            else if(logs[i]!="./")
                ++ans;
        }
        return ans;
    }
};
