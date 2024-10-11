// https://cses.fi/problemset/task/1622
// Creating Strings

#include <bits/stdc++.h>
 
#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<50;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};
 
void backtracking(int index, int N, std::string& S, std::string& opt, std::set<std::string>& ans);
 
int32_t main(){
 
    std::ios::sync_with_stdio(0), std::cin.tie(0);
 
    int N;
    std::string S, opt;
    std::set<std::string> ans;
 
    std::cin>>opt;
    N = opt.size();
    S.resize(N);
 
    backtracking(0,N,S,opt,ans);
 
    std::cout<<ans.size()<<'\n';
    for(std::string str : ans)
        std::cout<<str<<'\n';
 
    return 0;
}
 
void backtracking(int index, int N, std::string& S, std::string& opt, std::set<std::string>& ans){
    if(index==N){
        ans.insert(S);
        return;
    }
 
    for(int i=0; i<N; ++i){
        if(opt[i]=='0')
            continue;
        S[index] = opt[i];
        opt[i] = '0';
        backtracking(index+1,N,S,opt,ans);
        opt[i] = S[index];
    }
    
}
