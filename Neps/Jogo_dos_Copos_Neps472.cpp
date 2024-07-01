// https://neps.academy/br/exercise/472
// Jogo dos Copos

#include <bits/stdc++.h>

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int moves, move;
    char cup;

    std::cin>>moves;
    
    std::cin>>cup;

    while(moves--){
        std::cin>>move;
        switch(move){
            case 1: if(cup=='A' || cup=='B') cup = cup=='A'? 'B' : 'A'; break;
            case 2: if(cup=='B' || cup=='C') cup = cup=='B'? 'C' : 'B'; break;
            case 3: if(cup=='A' || cup=='C') cup = cup=='A'? 'C' : 'A'; break;
        }
    }

    std::cout<<cup<<'\n';

    return 0;
}
