// https://leetcode.com/problems/find-the-middle-index-in-array
// 1991 - Find the Middle Index in Array

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int tam=nums.size(),aux=nums[0];
        vector<int> suffix(tam);
        suffix[tam-1]=nums[tam-1];

        for(int i=tam-2; i>=0; --i)    
            suffix[i]=suffix[i+1]+nums[i];
        
        if(suffix[0]-nums[0]==0)
            return 0;

        for(int i=1; i<(tam-1); ++i){
            std::cout<<aux<<" x "<<suffix[i+1]<<'\n';
            if(aux==suffix[i+1])
                return i;
            aux+=nums[i];
        }

        if(aux==0)
            return tam-1;
        
        return -1;
    }
};
