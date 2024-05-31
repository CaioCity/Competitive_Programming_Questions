// https://neps.academy/br/exercise/265

#include <bits/stdc++.h>

int main(){

    short int N,aux;
    int L;
    std::cin>>N>>L;

    std::queue<short int> Queue;
    std::map<std::pair<int,short int>,int> man;

    for(int i=1; i<=N; i++)
        man.insert(std::make_pair(std::make_pair(0,i),0));

    for(int i=0; i<L; i++){
        std::cin>>aux;
        Queue.push(aux);
    }

    while(!Queue.empty()){
        int time = (man.begin()->first).first;
        int ident = (man.begin()->first).second;
        int number = man.begin()->second;
        aux=Queue.front();
        Queue.pop();
        man.erase(man.begin());
        man.insert(std::make_pair(std::make_pair(time+aux,ident),number+1));
    }

    std::vector<std::pair<short int, int>> sorteado;
    for(auto p : man)
        sorteado.push_back(std::make_pair((p.first).second, p.second));

    std::sort(sorteado.begin(),sorteado.end());

    for(auto i : sorteado)
        std::cout<<i.first<<" "<<i.second<<'\n';

    return 0;
}
