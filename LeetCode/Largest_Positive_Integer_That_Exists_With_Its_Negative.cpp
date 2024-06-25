// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/
// Largest Positive Integer That Exists With Its Negative

class Solution {
public:
    int findMaxK(vector<int>& nums) {

        short int tam=nums.size();
        vector <int> posit,negat;
        for(short int i=0; i<tam; i++){
            if(nums[i]>0)
                posit.push_back(nums[i]);
            else
                negat.push_back(nums[i]*(-1));
        }
        
        short int tampos=posit.size(), tamneg=negat.size();
        sort(posit.begin(), posit.begin()+tampos);
        sort(negat.begin(), negat.begin()+tamneg);

        for(short int i= (tampos-1), j=(tamneg-1); i>=0 && j>=0; ){
            
            if( posit[i] == negat[j] )
                return posit[i];
            else if( posit[i] < negat[j] )
                j--;
            else if (posit[i] > negat[j] )
                i--;

        }

        return -1;
    }
};
