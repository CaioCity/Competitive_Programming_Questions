// https://judge.beecrowd.com/en/problems/view/1100
// 1100 - Knight Moves

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<40;
#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';

typedef std::tuple<int,int,int> trio;
int L[] = {-2,-1,1,2,2,1,-1,-2}, C[] = {1,2,2,1,-1,-2,-2,-1};

bool valid(int L, int C){
    if(0<=L && L<8 && 0<=C && C<8)
        return 1;
    return 0;
}

int32_t main(){

    // std::ios::sync_with_stdio(0),std::cin.tie(0);

    int L1,L2,C1,C2,x,y,T;
    char S[10];

    int count =0;

    while(scanf(" %[^\n]s", S) != EOF){
    
        L1 = S[1]-'1'; L2 = S[4]-'1';
        C1 = S[0]-'a'; C2 = S[3]-'a';

        bool grid[9][9]={{0}};

        T = 0;
        std::queue<trio> Q;
        Q.push({L1,C1,T});

        while(!Q.empty()){

            std::tie(x,y,T) = Q.front();
            Q.pop();

            if(grid[x][y])
                continue;
            grid[x][y]=1;

            if(x==L2 && y==C2){
                std::cout<<"To get from "<<char(C1+'a')<<L1+1<<" to "<<char(C2+'a')<<L2+1<<" takes "<<T<<" knight moves.\n";\
                break;
            }

            for(int i=0; i<8; ++i)
                if(valid(x+L[i],y+C[i]) && !grid[x+L[i]][y+C[i]])
                    Q.push({x+L[i],y+C[i],T+1});
        }
    }

    return 0;
}
