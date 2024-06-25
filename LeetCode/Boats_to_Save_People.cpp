// https://leetcode.com/problems/boats-to-save-people/description/
// Boats to Save People

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), (people.begin()+people.size()));
        int boats=0,lib=0;
        for(int i=0,j=people.size()-1; i<j; boats++, j--,lib++ )
            if((people[i]+people[j])<=limit){
                i++;
                lib++;
            }
                
        if(lib<people.size())
            boats++;    
        return boats;
    }
};
