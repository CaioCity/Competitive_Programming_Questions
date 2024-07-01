// https://neps.academy/br/exercise/22
// Jogo de Tabuleiro

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int L, A, B;
    std::cin >> L;

    int grid[L][L];

    for (int i = 0; i < L; ++i)
        for (int j = 0; j < L; ++j)
            std::cin >> grid[i][j];

    std::queue<std::pair<int, int>> fila;

    fila.push({ 1,1 });

    while (!fila.empty()) {
        
        std::tie(A, B) = fila.front();
        fila.pop();

        if(grid[A][B]!=9)
            continue;

        if (grid[A][B - 1] + grid[A - 1][B] + grid[A - 1][B - 1] < 2)
            grid[A][B] = 1;
        else
            grid[A][B] = 0;

        if (A + 1 < L)
            fila.push({ A + 1,B });
        if (B + 1 < L)
            fila.push({ A,B + 1 });

    }

    std::cout << grid[L - 1][L - 1] << '\n';

    return 0;
}
