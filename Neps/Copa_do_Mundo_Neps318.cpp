// https://neps.academy/br/exercise/318
// Copa dp Mundo (OBI 2014)

#include <bits/stdc++.h>

typedef std::tuple<int, int, int> trio;

int find(int A, int leader[]);

void unir(int A, int B, int leader[], std::vector<int>& conex);

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,F,R;
    int A,B,C,count=0,ans=0;
    std::cin>>N>>F>>R;

    std::priority_queue<trio,std::vector<trio>, std::greater<trio>> filaR, filaF;
    std::vector<int> conex (N+4,1);
    int leader[N+4];
    for(int i=0; i<=N; i++)
        leader[i]=i;

    for(int i=0; i<F; i++){
        std::cin>>A>>B>>C;
        filaF.push({C,A,B});
    }
    for(int i=0; i<R; i++){
        std::cin>>A>>B>>C;
        filaR.push({C,A,B});
    }

    while(count<(N-1) && !filaF.empty()){
        std::tie(C,A,B)=filaF.top();
        filaF.pop();

        A=find(A,leader); B=find(B,leader);
        if(A==B)
            continue;

        unir(A,B,leader,conex);

        count++;
        ans+=C;
    }

    while(count<(N-1) && !filaR.empty()){
        std::tie(C,A,B)=filaR.top();
        filaR.pop();

        A=find(A,leader); B=find(B,leader);
        if(A==B)
            continue;

        unir(A,B,leader,conex);

        count++;
        ans+=C;
    }

    std::cout<<ans<<'\n';

    return 0;
}

int find(int A, int leader[]){
    int aux=A,next;
    while(leader[A]!=A){
        A=leader[A];
    }

    while(leader[aux]!=aux){
        next=leader[aux];
        leader[aux]=A;
        aux=next;
    }

    return A;
}

void unir(int A, int B, int leader[], std::vector<int>& conex){
    if(conex[A]>conex[B]){
        leader[B]=A;
        conex[A]+=conex[B];
    }
    else{
        leader[A]=B;
        conex[B]+=conex[A];
    }
}
