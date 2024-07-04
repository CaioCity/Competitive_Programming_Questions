// https://neps.academy/br/exercise/298
// Reduzindo Detalhes de um Mapa

#include <bits/stdc++.h>

using namespace std;
int main(){

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N,M,U,V,C,T;
    cin>>N>>M;

    int visited = 1, ans = 0;
    vector<vector<pair<int,int>>> edges (N+1);
    bool* anexo = (bool*)calloc(N+1,sizeof(bool));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

    for(int i=0; i<M; ++i){
        cin>>U>>V>>C;
        edges[U].push_back({V,C});
        edges[V].push_back({U,C});
    }

    anexo[1]=1;
    for( auto [V,C] : edges[1] )
        heap.push({C,V});

    while( !heap.empty() ){

        tie(C,V)=heap.top();
        heap.pop();

        if(anexo[V])
            continue;

        anexo[V]=1;

        ans+=C;
        
        if(++visited == N)
            break;

        for(auto [T,Cost] : edges[V])
            heap.push({Cost,T});
    }

    cout<<ans<<'\n';

    return 0;
}
