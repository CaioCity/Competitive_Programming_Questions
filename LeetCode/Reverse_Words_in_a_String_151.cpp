// https://leetcode.com/problems/reverse-words-in-a-string/description
// 151 - Reverse Words in a String

class Solution {
public:
    void word(int& i, int tam, int index, string& S, string& ans){
        int begin=i, end;
        
        while(i<tam && S[i]!=' '){
            ++i;
            // std::cout<<i<<' ';
        }
        if(i==tam){    
            --i;
            for(; i>=begin; --i)
                ans+=S[i];
                i=tam;
            return;
        }
        for(end=i-1; begin<=end; --end)
            ans+=S[end];
        ans+=' ';
    }

    string reverseWords(string s) {
        string ans;
        int tam=s.size(), index=0;
        reverse(s.begin(),s.end());
        for(int i=0; i< tam; ++i)
            if(s[i]!=' ')
                word(i,tam,index,s,ans);
        if(ans[ans.size()-1]==' ')
            ans.pop_back();
        return ans;
    }
};
