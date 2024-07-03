// https://neps.academy/br/exercise/207
// Relogios

#include <bits/stdc++.h>

int mx[4] = { 1,0,-1,0 }, my[4] = { 0,1,0,-1 };

typedef std::tuple<int, int, int> trio;

int sum (int H, int K){
    if(H+1==K)
        return 0;
    return H+1;
}

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int L, C, K;
    std::cin >> L >> C >> K;

    std::vector<std::vector<std::pair<int,int>>> grid (L, std::vector<std::pair<int,int>> (C,{0,INT32_MAX}));
    for (int i = 0; i < L; ++i)
        for (int j = 0; j < C; ++j)
            std::cin >> grid[i][j].first;

    std::priority_queue<trio, std::vector<trio>, std::greater<trio> > fila;
    fila.push({ 0,0,0 });

    int T, A, B, H, ans=INT32_MAX; 
        
    while (!fila.empty()) {

        std::tie(T, A, B) = fila.top();
        fila.pop();
        
        if(grid[A][B].second <= T)
            continue;

        if(A==(L-1) && B==(C-1))
            ans=std::min(ans,T);

        H=T%K;
        for (int l = 0; l < 4; ++l)
            if (A + my[l] < L && A + my[l] >= 0 && B + mx[l] >= 0 && B + mx[l] < C) {
                if (grid[A + my[l]][B + mx[l]].first == -1 || grid[A + my[l]][B + mx[l]].first == sum(H,K))
                    fila.push({ T + 1,A + my[l],B + mx[l] });
                else if (grid[A][B].first == -1) {
                    int aux = grid[A + my[l]][B + mx[l]].first <= H ? grid[A + my[l]][B + mx[l]].first + K - H : grid[A + my[l]][B + mx[l]].first - H;
                    fila.push({ T+aux, A + my[l], B + mx[l] });
                }
            }
        grid[A][B].second=T;
    }

    if(ans==INT32_MAX)
        std::cout<<"-1\n";
    else std::cout<<ans<<'\n';

    return 0;
}
