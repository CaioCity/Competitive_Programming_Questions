// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
// 1894 - Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int tam = chalk.size();
        int64_t sum=0;
        for(int i=0; i<tam;++i)
            sum+=chalk[i];
        k%=sum;
        for(int i=0; i<tam; ++i){
            if(k<chalk[i])
                return i;
            else k-=chalk[i];
        }
        return 0;
    }
};
