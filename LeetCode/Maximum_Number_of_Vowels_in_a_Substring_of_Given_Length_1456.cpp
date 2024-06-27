// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description
// 1456 - Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    bool vowel(char x){
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
            return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int loop=s.size()-k,max, atual=0;
        for(int i=0; i<k; ++i)
            if(vowel(s[i]))
                ++atual;
        max=atual;
        for(int i=1; i<=loop; ++i){
            if(vowel(s[i-1]))
                --atual;
            if(vowel(s[i+k-1]))
                ++atual;
            max=std::max(atual,max);
        }
        return max;
    }
};
