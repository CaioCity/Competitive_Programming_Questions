// https://neps.academy/br/competition/2006/exercise/2749
// C - Espelhos

#include <bits/stdc++.h>

#define int int64_t

void build(int index, int L, int R, int V[], int seg[]){
    if(L==R)
        seg[index] = V[L];
    else{
        int mid = (L+R)>>1;
        build(index<<1, L, mid, V, seg);
        build((index<<1)|1, mid+1, R, V, seg);
        seg[index] = seg[index<<1] + seg[(index<<1)|1];
    }   
}

int query(int index, int L, int R, int QL, int QR, int seg[]){
    if(QR<L || QL>R)
        return 0;
    if(L>=QL && R<=QR)
        return seg[index];
    
    int mid = (L+R)>>1;
    
    return query(index<<1, L, mid, QL, QR, seg) + query((index<<1)|1, mid+1, R, QL, QR, seg);
}

int32_t main (){

//    std::ios::sync_with_stdio(0), std::cin.tie(0);

    char S[30];
    int N, Q, L, R, index;
    std::cin>>N;
    
    int seg[(N+3)<<2], V[N+1];
    
    for(int i=1; i<=N; ++i)
        std::cin>>V[i];
        
    build(1,1,N,V,seg);
    
    std::cin>>Q;
    
    for(int i=0; i<Q; ++i){
        scanf(" %[^\n]s", S);
       
        if(S[0]=='?'){
            L=R=0;
            index = (int)strlen(S)-1;
            for(int i=1; S[index]!=' '; --index, i*=10)
                R+=((S[index]-'0')*i);
            
            --index;
            for(int i=1; S[index]!=' '; --index, i*=10)
                L+=((S[index]-'0')*i);
            
            if(query(1,1,N,L,R,seg)%3 == 0)
                std::cout<<"S\n";
            else std::cout<<"N\n";
        }
    }

    return 0;
}
