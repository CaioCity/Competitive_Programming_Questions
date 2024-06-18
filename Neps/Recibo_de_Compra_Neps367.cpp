// https://neps.academy/br/exercise/367
// Recibo de Compra

#include <bits/stdc++.h> 

void backtracking (short int index, short int R, short int K, int sum, int valor[]);

int64_t ans;

int main(){
    
    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    short int R,K;
    std::cin>>R>>K;
    int* valor=(int*)calloc(K,sizeof(int));
    backtracking(0,(R-(K*(K+1))/2),K,0,valor);
    std::cout<<ans<<'\n';

    return 0;
}

void backtracking (short int index, short int R, short int K, int sum, int valor[]){

    if(index==(K-1)){
        if(sum<=R)
            ++ans;
        return;
    }
    else{
        int count=0;
        while((K-index)*count<=(R-sum)){
            valor[index]=count;
            backtracking(index+1, R, K, sum+(K-index)*count, valor);
            ++count;
        }
    }
    return ;
}
