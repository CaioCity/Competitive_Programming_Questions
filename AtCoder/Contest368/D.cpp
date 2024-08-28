// https://atcoder.jp/contests/abc368/tasks/abc368_d
// D - Minimum Steiner Tree

#include <bits/stdc++.h>

#define int int64_t

void path(int curr, int last[], bool points[]){
    while(!points[curr]){
        points[curr]=1;
        curr = last[curr];
    }
}

void dfs(int curr, int last[], bool points[], std::unordered_set<int>& S, std::vector<std::vector<int>>& edges){
        if(S.find(curr)!=S.end()){
            S.erase(curr);
            path(curr,last,points);
        }

        for(int V : edges[curr])
            if(V!=last[curr]){
                last[V] = curr;
                dfs(V,last,points,S,edges);
            }
}

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,K,U,V,ans = 0;
    std::cin>>N>>K;

    std::vector<std::vector<int>> edges(N+1,std::vector<int>(0));
    std::unordered_set<int> S;
    int *last = (int*)calloc(N+1,sizeof(int));
    bool *points = (bool*)calloc(N+1,sizeof(bool));

    for(int i=1; i<N; ++i){
        std::cin>>U>>V;
        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    for(int i=0; i<K; ++i){
        std::cin>>U;
        S.insert(U);
    }

    V = *S.begin();
    S.erase(V);
    last[V] = -1;
    points[V] = 1;
    dfs(V,last,points,S,edges);

    for(int i =0 ; i<=N; ++i)
        if(points[i])
            ++ans;

    std::cout<<ans;

    return 0;
}
