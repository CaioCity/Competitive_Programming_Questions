// https://neps.academy/br/exercise/2320
// Subsequencia

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int A,B,maior=0,target;
    bool find=0;

    std::cin>>A>>B;

    int l1[A],l2[B];
    for(int& i : l1)
        std::cin>>i;
    
    for(int i=0; i<B; i++){
        find=0;
        std::cin>>target;
        for(int j=maior; j<A; j++){
            if(l1[j]==target){
                maior=j+1;
                find=1;
                break;
            }
        }
        if(!find){
            std::cout<<"N\n";
            return 0;
        }
    }
    
    std::cout<<"S\n";
    return 0;
}
