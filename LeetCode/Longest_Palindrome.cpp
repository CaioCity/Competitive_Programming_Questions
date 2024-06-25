// https://leetcode.com/problems/longest-palindrome/ 
// Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> letras;
        for(char c : s)
            letras[c]++;

        int tam=0, impar=0;
        for( auto [c, i] : letras ){
            if(i&1)
                impar=1;
            if(i>=2){
                if(i&1)
                    tam+=(i-1);
                else 
                    tam+=i;
            }
        }

        return tam+impar;       
    }
};
