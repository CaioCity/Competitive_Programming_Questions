// https://leetcode.com/problems/can-place-flowers/description/
// 605 - Can Place Flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int seq=1;
        for(int i=0; i<flowerbed.size(); i++)
            if(!flowerbed[i])
                seq++;
            else{
                n-=((seq-1)/2);
                if(n<=0) return 1;
                seq=0;
            }
        n-=(seq/2);
        if(n<=0)
            return 1;
        else return 0;


    }
};
