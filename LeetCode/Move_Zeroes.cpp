// https://leetcode.com/problems/move-zeroes/description/
// Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int tam=nums.size();
        for(int i=0, j=1,cont_0=0; i<tam; i++){
            if(nums[i]==0){
                j=i+1;
                while(j<tam && nums[j]==0){
                    j++;
                }
                if(j<tam)
                    swap(nums[i],nums[j]);
            }
        }
        
    }
};
