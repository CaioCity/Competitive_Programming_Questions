// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/
// 1296 - Divide Array in Sets of K Consecutive Numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int K) {

        if(nums.size()%K!=0)
            return 0;
        if(nums.size()==1)
            return 1;

        map<int,int> numbers;
        for(int i :nums)
            numbers[i]++;
        
        map<int,int>::iterator fim=numbers.end();
        for(int i=1; i<K; i++)
            fim--;
        for(auto i=numbers.begin(); i!=fim; i++)
            while(i->second--!=0)
                for(int j=1; j<K; j++){
                    if(numbers[i->first+j]>0)
                        numbers[i->first+j]--;
                    else
                        return 0;
                }

        fim=numbers.end()--;
        for(int i=0; i<K; i++, fim--)
            if(fim->second!=0)
                return false;            

        return 1;
    }
};  
