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

// Código com debug

// #include <bits/stdc++.h>

// void backtracking (short int index, short int R, short int K, int sum, int valor[]);

// int64_t ans;

// int main(){

//     std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

//     short int R,K;
//     std::cin>>R>>K;
//     int* valor=(int*)calloc(K,sizeof(int));
//     backtracking(0,(R-(K*(K+1))/2),K,0,valor);
//     std::cout<<ans<<'\n';

//     return 0;
// }

// void backtracking (short int index, short int R, short int K, int sum, int valor[]){

//     if(index==(K-1)){
//         if(sum<=R){
//             int* prefix= (int*)calloc(K,sizeof(int)), debug;
//             debug=prefix[0]=valor[0]+1;
//             std::cout<<prefix[0]<<' ';
//             for(int i=1; i<(K-1); i++){
//                 prefix[i]=valor[i]+prefix[i-1]+1;
//                 debug+=prefix[i];
//                 std::cout<<prefix[i]<<' ';
//             } std::cout<<R-debug+(K*(K+1))/2<<'\n';
//             ++ans;
//         }    
//         return;
//     }
//     else{
//         int count=0;
//         while((K-index)*count<=(R-sum)){
//             valor[index]=count;
//             backtracking(index+1, R, K, sum+(K-index)*count, valor);
//             ++count;
//         }
//     }
//     return ;
// }
