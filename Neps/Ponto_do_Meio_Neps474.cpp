// https://neps.academy/br/exercise/474
// Ponto do Meio

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int64_t N,L=1;
    std::cin>>N;

    for(int i=1; i<=N; ++i)
        L<<=1;

    ++L;

    std::cout<<L*L<<'\n';

    return 0;
}
