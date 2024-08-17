// https://leetcode.com/problems/maximum-distance-in-arrays/description
// 624 - Maximum Distance in Arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min, min2, max, max2, Vmin, Vmax, tam = arrays.size();
        min = min2 = INT32_MAX;
        max = max2 = INT32_MIN;
        for(int i=0; i<tam; ++i){
            if(min2 > arrays[i].front()){
                if(min > arrays[i].front()){
                    min2 = min;
                    min = arrays[i].front();
                    Vmin = i;
                }
                else min2 = arrays[i].front();
            }
            if(max2 < arrays[i].back()){
                if(max < arrays[i].back()){
                    max2 = max;
                    max = arrays[i].back();
                    Vmax = i;
                }
                else max2 = arrays[i].back();
            }
        }

        if(Vmax != Vmin) return max - min; 
        else return (max-min2)>(max2-min)?(max-min2):(max2-min); 
    }
};
