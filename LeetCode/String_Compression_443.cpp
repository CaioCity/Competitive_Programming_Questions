// https://leetcode.com/problems/string-compression/description
// 443 - String Compression

class Solution {
public:
    char conversor (int x){
        return (char)((int)'0' + x);
    }
    void number (int& index, int repet, vector<char>& chars){        
        if(repet>=1000)
            chars[index++]=conversor(repet/1000);
        if(repet>=100)
            chars[index++]=conversor((repet/100)%10);
        if(repet>=10)
            chars[index++]=conversor((repet/10)%10);
        chars[index++]=conversor(repet%10);
    }
    int compress(vector<char>& chars) {
        int index=0, repet=1, tam = chars.size();
        std::cout<<chars.size()<<'\n';
        char C=chars[0];
        for(int i=1; i<tam; ++i){
            // std::cout<<"i = "<<i<<" index = "<<index<<'\n';
            if(chars[i]==C)
                ++repet;
            else {
                chars[index++] = C;
                C=chars[i];
                if(repet>1)
                    number(index,repet,chars);
                repet=1;
            }
        }
        chars[index++] = C;
        if(repet>1)
            number(index,repet,chars);
        // std::cout<<index;
        return index;
    }
};
