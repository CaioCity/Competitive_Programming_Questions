// https://neps.academy/br/exercise/2
// Medalhas

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int A,B,C;

    std::cin>>A>>B>>C;

    if(!(A>B ^ A>C)){
        if(A>B){
            if(B>C)
                std::cout<<"3\n2\n";
            else std::cout<<"2\n3\n";
            std::cout<<"1\n";
        } else{
            std::cout<<"1\n";
            if(B>C)
                std::cout<<"3\n2\n";
            else std::cout<<"2\n3\n";
        }
    } else{
        if(A>B)
            std::cout<<"2\n1\n3\n";
        else std::cout<<"3\n1\n2\n";   
    }

    return 0;
}
