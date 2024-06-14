// https://codeforces.com/contest/1985/problem/E
// Secret Box

#include <bits/stdc++.h>

void div(std::vector<int>& divisors, int64_t k);

int main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    short int t;
    std::cin>>t;
    while(t--){
        short int x,y,z;
        int64_t V,ans=0,aux=0,a,b,c;
        std::cin>>x>>y>>z>>V;

        std::vector<int> divk;
        div(divk,V);

        int tam = divk.size(); 
        for(int i=0; i<tam; i++){
            for(int j=i; j<tam; j++){
                a=divk[i]; b=divk[j]; c=V/(a*b);
                if((a*b*c)!=V)
                    continue;
                int64_t moves[6][3]={{a,b,c},{a,c,b},{b,a,c},{b,c,a},{c,a,b},{c,b,a}};
                
                for(short int l=0; l<6; l++)
                    if((x-moves[l][0]+1)>0 && (y-moves[l][1]+1)>0 && (z-moves[l][2]+1)>0){
                        aux= (x-moves[l][0]+1)*(y-moves[l][1]+1)*(z-moves[l][2]+1);
                        ans=std::max(aux,ans);
                    }
            }
        }
      
        std::cout<<ans<<'\n';
    }

    return 0;
}

void div(std::vector<int>& divisors,int64_t k){
    for(int64_t i=1; i*i<=k; i++)
        if(k%i==0){
            divisors.push_back(i);
            divisors.push_back(k/i);
        }
            
    return ;
}
