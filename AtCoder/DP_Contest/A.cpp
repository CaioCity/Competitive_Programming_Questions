// https://atcoder.jp/contests/dp/tasks/dp_a
// Frog 1

#include <bits/stdc++.h>

int DP( int target, int stone[], std::vector<int>& cost){
    if(cost[target]!=-1) return cost[target];
    if(target<=3)
        return cost[target] = std::abs(stone[target] - stone[1]);
    return cost[target] = std::min(DP(target-1, stone, cost) + std::abs(stone[target] - stone[target-1]), 
                                   DP(target-2, stone, cost) + std::abs(stone[target] - stone[target-2]));
}

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N;
    std::cin>>N;

    std::vector<int> cost (N+1,-1);
    cost[1]=0;

    int stone[N+1];
    for(int i=1; i<=N; ++i)
        std::cin>>stone[i];

    std::cout<< DP(N, stone, cost) <<'\n';

    return 0;
}
