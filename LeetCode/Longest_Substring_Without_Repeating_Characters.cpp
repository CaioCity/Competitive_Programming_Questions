// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> hash;
        int tam=s.size(), last=0,maior=0,curr=0;
        for(int i=0; i<tam; i++)
            if(hash.find(s[i])==hash.end()){
                curr++;
                hash[s[i]]=i;
            }
            else{
                maior=max(maior,curr);
                last=max(hash[s[i]],last);
                curr=i-last;
                hash[s[i]]=i;    
            }
        return max(maior,curr);
    }
};
