// https://neps.academy/br/exercise/906
// Human Learning

#include <bits/stdc++.h>

int main(){
    
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,K;
    long long int answer=0;
    std::cin>>N>>K;

    int64_t alunos[N];

    for(int i=0; i<N; i++)
        std::cin>>alunos[i];
    
    std::sort(alunos, alunos+N, std::greater<int>());

    int grupos= floor(N/K);

    for(int i=0; i<grupos; i++)
        answer+=alunos[i]*K;

    if(N%K)
        answer+=alunos[grupos]*(N%K);

    std::cout<<answer<<'\n';

    return 0;
}
