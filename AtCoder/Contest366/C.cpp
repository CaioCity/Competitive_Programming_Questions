// https://atcoder.jp/contests/abc366/tasks/abc366_c
// C - Balls and Bag Query

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int Q,op;
    std::cin>>Q;

    std::map<int,int> S;

    for(int i=0; i<Q; ++i){
        std::cin>>op;
        switch(op){
            case 1: 
                std::cin>>op;
                ++S[op];
                break;
            case 2: 
                std::cin>>op;
                if(S[op]==1)
                    S.erase(op);
                else --S[op];
                break;
            case 3:
                std::cout<<S.size()<<'\n';
                break;
        }
    }

    return 0;
}
