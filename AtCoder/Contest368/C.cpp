// https://atcoder.jp/contests/abc368/tasks/abc368_c
// C - Triple Attack

// Seguem 2 codes, o institivo e o otimizado em space O(1)

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,ans=0;
    std::cin>>N;    

    int V[N];
    for(int i=0; i<N; ++i)
        std::cin>>V[i];
    
    for(int i=0; i<N; ++i){
        
        ans += 3*(V[i]/5);
        V[i]%=5;
        while(V[i]>0){
            ++ans;
            if(ans%3==0)
                V[i]-=3;
            else --V[i];          
        }
    }

    std::cout<<ans<<'\n';

    return 0;
}

// Space O(1)
#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,ans=0;
    std::cin>>N;    

    int giant;
    
    for(int i=0; i<N; ++i){
        std::cin>>giant;
        ans += 3*(giant/5);
        giant%=5;
        while(giant>0){
            ++ans;
            if(ans%3==0)
                giant-=3;
            else --giant;          
        }
    }

    std::cout<<ans<<'\n';

    return 0;
}
