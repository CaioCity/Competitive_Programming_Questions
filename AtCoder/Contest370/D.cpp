// https://atcoder.jp/contests/abc370/tasks/abc370_d
// D - Cross Explosion

#include <bits/stdc++.h>

#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';
#define int int64_t
const int INF = 1ll<<56;

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int H,W,Q,R,C,TR,TC;
    std::cin>>H>>W>>Q;

    std::vector<int> Vline(W), Vcol(H);
    for(int i=0; i<W; ++i)
        Vline[i] = i;
    for(int i=0; i<H; ++i)
        Vcol[i] = i;

    std::set<int>::iterator it;
    std::set<int> Sline (Vline.begin(),Vline.end()), Scol(Vcol.begin(),Vcol.end());
    std::vector<std::set<int>> lines(H,Sline), cols(W,Scol);

    int F=0;

    while(Q--){
        std::cin>>R>>C;
        --R; --C;

        if(lines[R].find(C)!=lines[R].end()){
            ++F;
            lines[R].erase(lines[R].find(C));
            cols[C].erase(cols[C].find(R));
            continue;
        }

        it = lines[R].lower_bound(C);
        if(!lines[R].empty() && it !=lines[R].begin()){
            --it;
            ++F;
            TC = *it;
            lines[R].erase(it);
            cols[TC].erase(cols[TC].find(R));
        }   

        it = lines[R].upper_bound(C);
        if(it!=lines[R].end()){
            TC = *it;
            ++F;
            lines[R].erase(it);
            cols[TC].erase(cols[TC].find(R));
        } 

        it = cols[C].lower_bound(R);
        if(!cols[C].empty() && it !=cols[C].begin()){
            --it;
            TR = *it;
            ++F;
            cols[C].erase(it);
            lines[TR].erase(lines[TR].find(C));
        }

        it = cols[C].upper_bound(R);
        if(it!=cols[C].end()){
            TR = *it;
            ++F;
            cols[C].erase(it);
            lines[TR].erase(lines[TR].find(C));
        } 

    }

    int ans = 0;
    for(auto S : lines)
        ans+=S.size();

    std::cout<<ans<<'\n';
    
    return 0;
}
