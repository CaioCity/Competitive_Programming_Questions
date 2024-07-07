// https://leetcode.com/problems/find-the-encrypted-string/description/
// 3210 - Find the Encrypted String

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int tam=s.size();
        while((tam+k)>=s.size())
            s+=s;
            
        for(int i=0; i<tam; ++i)
            swap(s[i], s[i+k]);

        s.erase(s.begin()+tam,s.end());
        return s;
    }
};
