// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description
// 1190 - Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> open;
        vector<pair<int,int>> brackets;
        string ans;
        int tam = s.size(), extra=0;
        for(int i = 0; i<tam; ++i){
            switch(s[i]){
                case '(' : open.push(i-extra); ++extra; break;
                case ')' : brackets.push_back({open.top(),i-extra}); ++extra; open.pop(); break;
                default : ans.push_back(s[i]);
            }
        }
        int begin, end;
        for(int i = 0, loop = brackets.size(); i<loop; ++i){
            tie(begin,end) = brackets[i];
            reverse(ans.begin()+begin, ans.begin()+end);
        }

        return ans;
    }
};
