// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/
// 1061 - Lexicographically Smallest Equivalent String

class Solution {
public:
    char find(char A, unordered_map<char,char>& leader){
        if(A==leader[A])
            return A;
        return leader[A] = find(leader[A],leader);
    }

    void join(char A, char B, unordered_map<char,char>& leader){
        if(A>B)
            swap(A,B);
        leader[B] = leader[A];
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int tam=s1.size();
        char a,b;
        unordered_map<char,char> leader;
        for(char C ='a'; C<='z'; ++C)
            leader[C] = C;

        for(int i=0; i<=tam; ++i){
            a = s1[i]; b = s2[i];
            a = find(a,leader); b = find(b,leader);
            if(a!=b)
                join(a,b,leader);
        }

        for(auto [c,C] : leader)
            std::cout<<c<<" -> "<<C<<'\n';

        for(char& c : baseStr)
            c = find(leader[c],leader);
        
        return baseStr;
    }
};
