// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/
// 3211 - Generate Binary Strings Without Adjacent Zeros

class Solution {
public:
    void build(int index, string& S, int tam, vector<string>& ans){
        if(index==tam){
            ans.push_back(S);
            return;
        }

        S[index]='1';
        build(index+1,S,tam,ans);

        if(S[index-1]=='1'){
            S[index]='0';
            build(index+1,S,tam,ans);
        }

    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string S;
        S.resize(n+5);
        S[0]='1';
        build(1,S,n,ans);
        S[0]='0';
        build(1,S,n,ans);
        return ans;
    }
};
