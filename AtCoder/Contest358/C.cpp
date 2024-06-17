// https://atcoder.jp/contests/abc358/tasks/abc358_c
// Popcorn

#include <bits/stdc++.h>

int backtracking(int index, int N, int M, bool subset[], std::vector<std::string>& grid);

int count(int N, int M, bool subset[], std::vector<std::string>& grid);

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N, M;
    std::cin >> N >> M;

    bool subset[N];

    std::vector<std::string> grid(N);
    for (int i = 0; i < N; i++)
        std::cin >> grid[i];

    int ans = backtracking(0, N, M, subset, grid);
    std::cout << ans << '\n';

    return 0;
}

int backtracking(int index, int N, int M, bool subset[], std::vector<std::string>& grid) {
    int ans;
    if (index == (N - 1)) {

        subset[index] = 1;
        ans = count(N, M, subset, grid);
        subset[index] = 0;
        ans = std::min(ans, count(N, M, subset, grid));
    }
    else {
        subset[index] = 1;
        ans = backtracking(index + 1, N, M, subset, grid);
        subset[index] = 0;
        ans = std::min(ans, backtracking(index + 1, N, M, subset, grid));
    }
    return ans;
}

int count(int N, int M, bool subset[], std::vector<std::string>& grid) {
    bool* visit = (bool*)calloc(M, sizeof(bool));
    int number = 0, visitadas = 0;

    for (int i = 0; i < N; i++) {
        if (subset[i]) {
            number++;
            for (int j = 0; j < M; j++){
                if (grid[i][j] == 'o')
                    visit[j] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
        if (visit[i])
            visitadas++;

    free(visit);
    if (visitadas == M)
        return number;
    else return INT32_MAX;
}

// Versão com debugs
// #include <bits/stdc++.h>

// int backtracking(int index, int N, int M, bool subset[], std::vector<std::string>& grid);

// int count(int N, int M, bool subset[], std::vector<std::string>& grid);

// int debug;

// int main() {

//     std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

//     int N, M;
//     std::cin >> N >> M;

//     bool subset[N];

//     std::vector<std::string> grid(N);
//     for (int i = 0; i < N; i++)
//         std::cin >> grid[i];

//     int ans = backtracking(0, N, M, subset, grid);
//     std::cout << ans << '\n';

//     // std::cout<<debug<<" possibilidades\n";
//     return 0;
// }

// int backtracking(int index, int N, int M, bool subset[], std::vector<std::string>& grid) {
//     int ans;
//     if (index == (N - 1)) {

//         subset[index] = 1;
//         // std::cout<<"jogando esse cara para analise\n";
//         // for(int i=0; i<N; i++)
//         //     std::cout<<subset[i]<<' ';
//         // std::cout<<'\n';
//         ans = count(N, M, subset, grid);
//         subset[index] = 0;
//         // std::cout<<"jogando esse cara para analise\n";
//         // for(int i=0; i<N; i++)
//         //     std::cout<<subset[i]<<' ';
//         // std::cout<<'\n';
//         ans = std::min(ans, count(N, M, subset, grid));
//     }
//     else {
//         subset[index] = 1;
//         // std::cout<<"jogando esse cara para next\n";
//         // for(int i=0; i<N; i++)
//         //     std::cout<<subset[i]<<' ';
//         // std::cout<<'\n';
//         ans = backtracking(index + 1, N, M, subset, grid);
//         subset[index] = 0;
//         // std::cout<<"jogando esse cara para next\n";
//         // for(int i=0; i<N; i++)
//         //     std::cout<<subset[i]<<' ';
//         // std::cout<<'\n';
//         ans = std::min(ans, backtracking(index + 1, N, M, subset, grid));
//     }
//     return ans;
// }

// int count(int N, int M, bool subset[], std::vector<std::string>& grid) {
//     debug++;
//     bool* visit = (bool*)calloc(M, sizeof(bool));
//     int number = 0, visitadas = 0;

//     // std::cout<<"recebido:\n";
//     // for (int i = 0; i < N; i++)
//     //     std::cout<<subset[i]<<' ';
//     //     std::cout<<'\n';

//     for (int i = 0; i < N; i++) {
//         if (subset[i]) {
//             number++;
//             for (int j = 0; j < M; j++){
//                 // std::cout<<grid[i][j];
//                 if (grid[i][j] == 'o')
//                     visit[j] = 1;
//                 // else visit[j] = 0;
//             }
//             // std::cout<<'\n';
//         }
//     }

//     for (int i = 0; i < M; i++)
//         if (visit[i])
//             visitadas++;
            
//     // for(int i=0; i<N; i++)
//     //     std::cout<<visit[i]<<' ';
//     // std::cout<<visitadas<<' '<<number<<'\n';

//     free(visit);
//     if (visitadas == M)
//         return number;
//     else return INT32_MAX;
// }
