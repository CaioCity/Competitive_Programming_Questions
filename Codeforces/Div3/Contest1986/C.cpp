// https://codeforces.com/contest/1986/problem/C
// Update Queries

#include <bits/stdc++.h>

    int main(){

        std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

        unsigned short int t;
        std::cin>>t;
        // std::cout<<"t = "<<t<<'\n';
        while(t--){
            int n,m;
            std::cin>>n>>m;
            // std::cout<<"n = "<<n<<" m = "<<m<<'\n';
            std::string S;
            std::cin.ignore();
            std::cin>>S;    
            // std::cout<<S<<'\n';

            int aux; std::set<int> ind;
            for(int i=0; i<m; i++){
                std::cin>>aux;
                ind.insert(aux);
            }

            std::cin.ignore();
            std::string C;
            std::cin>>C;
            // std::cout<<C<<'\n';

            std::sort(C.begin(),C.end());

            for(int i=0; !ind.empty(); ++i){
                S[*ind.begin()-1]=C[i];
                ind.erase(*ind.begin());
                // std::cout<<"S = "<<S<<'\n';
            }

            std::cout<<S<<'\n';

        }

        return 0;
    }
