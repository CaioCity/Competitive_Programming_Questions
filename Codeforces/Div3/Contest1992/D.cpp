// https://codeforces.com/contest/1992/problem/D
// Test of Love

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0); std::cout.tie(0), std::cin.tie(0);

    int t;
    std::cin>>t;

    while(t--){
        int n,range,nado;
        std::cin>>n>>range>>nado;

        std::string lake;
        std::cin>>lake;
        int pos=-1,skip;
        bool wood=0;

        while(1){
            
            skip=pos+range;

            if(skip>=n){
                std::cout<<"YES\n";
                break;
            }

            wood=0;
            for(int i = skip; i>pos; --i)
                if(lake[i]=='L'){
                    skip = i;
                    wood=1;
                    break;
                }

            if(wood){
                pos=skip;
                continue;
            }

            if(lake[skip]=='C')
                std::cout<<"NO\n";
            else{
                wood=0;
                pos = skip;
                while(pos<n && nado>=0){
                    if(lake[pos]=='C')
                        break;
                    if(lake[pos]=='L'){
                        wood=1;
                        break;
                    }
                    --nado;
                    ++pos;
                }

                if(wood==1){
                    --pos;
                    continue;
                }
                if(pos==n && nado>=0)
                    std::cout<<"YES\n";  
                else 
                    std::cout<<"NO\n"; 
            }
            break;
        }

    }

    return 0;
}
