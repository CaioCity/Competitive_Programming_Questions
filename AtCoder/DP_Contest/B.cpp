// https://atcoder.jp/contests/dp/tasks/dp_b
// Frog 2

#include <bits/stdc++.h>

int DP( int target, int K, int stone[], std::vector<int>& cost){
    if(cost[target]!=-1) return cost[target];
    cost[target] = INT32_MAX;
    for(int i=1; i<=K && target>i; ++i)
        cost[target] = std::min(DP(target-i, K, stone, cost) + std::abs(stone[target] - stone[target-i]), cost[target]);
    return cost[target];
}

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,K;
    std::cin>>N>>K;

    std::vector<int> cost (N+1,-1);
    cost[1]=0;

    int stone[N+1];
    for(int i=1; i<=N; ++i)
        std::cin>>stone[i];

    std::cout<< DP(N, K, stone, cost) <<'\n';

    return 0;
}
