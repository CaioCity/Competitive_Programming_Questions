// https://leetcode.com/problems/roman-to-integer/description/
// 13 - Roman to Integer

class Solution {
public:
    int num(char x){
        switch(x){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans=0,tam=s.size(),aux;
        ans=num(s[tam-1]);
        for(int i=tam-2; i>=0; --i){
            aux=num(s[i]);
            if(aux<num(s[i+1]))
                ans-=aux;
            else ans+=aux;
        }
        return ans;          
    }
};
