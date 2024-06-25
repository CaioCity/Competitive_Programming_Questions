// https://leetcode.com/problems/reverse-vowels-of-a-string/description/
// Reverse Vowels of a String

class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        vector<int> V;
        for(char c : s){
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
                V.push_back(i);
            i++;
        }
        cout<<V.size();
        if(V.size()&1){
            int i=0; int j=V.size()-1;
            while(i!=j)
                swap(s[V[i++]],s[V[j--]]);
        }
        else{
            int i=0,j=V.size()-1;
            while(i<j)
                swap(s[V[i++]],s[V[j--]]);
        }
        return s;
    }
};
