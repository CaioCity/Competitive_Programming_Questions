// https://atcoder.jp/contests/abc378/tasks/abc378_c
// C - Repeating

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<40;
#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int N;
    std::cin>>N;

    int A[N],B[N];
    std::unordered_map<int,int> hash;

    for(int i=0; i<N; ++i){
        std::cin>>A[i];
        hash[A[i]]=-1;
    }

    for(int i=0; i<N; ++i){
        std::cout<<hash[A[i]]<<' ';
        hash[A[i]] = i+1;
    }

    std::cout<<'\n';
  
    return 0;
}
