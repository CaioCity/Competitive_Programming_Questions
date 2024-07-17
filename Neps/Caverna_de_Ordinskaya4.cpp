// https://neps.academy/br/exercise/4
// Caverna de Ordinskaya

#include <bits/stdc++.h>

#define int int64_t

int32_t main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M, aux, last, sum;

    std::cin >> N >> M;

    std::cin >> last;
    last = std::min(last, M - last);
    sum = last;

    for (int i = 1; i < N; i++) {
        std::cin >> aux;
        if (aux < last) {
            if (M - aux < last) {
                std::cout << "-1\n";
                return 0;
            } else {
                last = M - aux;
            }
        } else {
            if (M - aux >= last) {
                last = std::min(aux, M - aux);
            } else {
                last = aux;
            }
        }
        sum += last;
    }

    std::cout << sum << '\n';

    return 0;
}
