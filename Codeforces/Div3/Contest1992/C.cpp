// https://codeforces.com/contest/1992/problem/C
// Gorilla and Permutation 

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

      int t;
  std::cin>>t;

  while(t--){
    int n,m,k;
    std::cin>>n>>m>>k;

    for(int i=n; i>k; --i)
      std::cout<<i<<' ';

    for(int i=k; i>m; --i)
      std::cout<<i<<' ';

    for(int i=1; i<=m; ++i)
      std::cout<<i<<' ';

    std::cout<<'\n';

  }
  
  return 0;
}
