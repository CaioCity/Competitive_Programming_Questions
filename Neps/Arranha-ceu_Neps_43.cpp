// https://neps.academy/br/exercise/43
// Arranha-Ceu -> Segtree

#include <bits/stdc++.h>

#define int int64_t

void build(int C, int L, int R, int V[], int seg[]){
    if(L==R)
        seg[C]=V[L];
    else{
        int mid = (L+R)>>1;
        build(C<<1,L,mid,V,seg);
        build((C<<1)+1,mid+1,R,V,seg);
        seg[C] = seg[C<<1] + seg[(C<<1)|1];
    }
}

void update(int C, int value, int index, int L, int R, int seg[]){
    if(L==R)
        seg[index]=value;
    else{
        int mid = (L+R)>>1;
        if(C<=mid)
            update(C, value, index<<1, L, mid, seg);
        else update(C, value, (index<<1)|1, mid+1, R, seg);
        seg[index] = seg[index<<1] + seg[(index<<1)|1];
    }
}

int query(int node, int L, int R, int QL, int QR, int seg[]){
    if(QR<L or QL>R) return 0;

    if(QL<=L and QR>=R) return seg[node];

    int mid = (L+R)>>1;
    return query((node<<1), L, mid, QL, QR, seg) + query((node<<1)+1, mid+1, R, QL, QR, seg);
}

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,Q, op, andar, val;
    std::cin>>N>>Q;

    int seg[(N+2)<<2], V[N+1];

    for(int i=1; i<=N; ++i)
        std::cin>>V[i];

    build(1, 1,N,V,seg);

    for(int i=0; i<Q; ++i){
        std::cin>>op>>andar;
        if(op==0){
            std::cin>>val;
            update(andar, val,1, 1, N, seg);
        }
        else std::cout<<query(1, 1,N, 1, andar, seg)<<'\n';
    }

    return 0;
}
