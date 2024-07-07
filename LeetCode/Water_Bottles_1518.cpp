// https://leetcode.com/problems/water-bottles/description
// 1518 - Water Bottles

int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles, retorna;
    while(1){
        retorna = numBottles/numExchange;
        if(retorna == 0)
            break;
        ans+=retorna;
        numBottles-=(retorna*numExchange);
        numBottles+=retorna;
    }
    return ans;
}
