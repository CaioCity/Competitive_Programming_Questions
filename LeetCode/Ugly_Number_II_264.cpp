// https://leetcode.com/problems/ugly-number-ii/description/
// 264 - Ugly Number II

class Solution {
public:
    int64_t nthUglyNumber(int n) {
        
        set<int64_t> S;
        S.insert(1);
        set<int64_t>::iterator i,j,k;
        int64_t m2=1,m3=1,m5=1;
        i=j=k=S.begin();
        
        while( S.size()<=n ){

            if(m2<=m3 && m2<=m5){
                S.insert(m2);
                ++i;
                if(i!=S.end()) m2= *i *2; 
            }
            else if(m3<m2 && m3<=m5){
                S.insert(m3);
                ++j;
                if(j!=S.end()) m3= *j *3; 
            } else {
                S.insert(m5);
                ++k;
                if(k!=S.end()) m5= *k *5;
            }
        }
        i=S.begin();
        advance(i,n-1);
        return *i;
    }
};
