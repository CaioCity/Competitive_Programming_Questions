// https://codeforces.com/contest/1986/problem/D
// Mathematical Problem

#include <bits/stdc++.h>

int num(char x){
    return (int)(x-'0');
}

int num(char x, char y){
    return (int)(10*(x-'0')) + (int)(y-'0');
}

int main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int t;
    std::cin>>t;

    while(t--){
        int n;
        bool apenas1=1,next=0;

        std::cin>>n;
        std::string S;
        std::cin>>S;

        if(n==1){
            std::cout<<S[0]<<'\n';
            continue;
        }
        if(n==2){
            std::cout<<num(S[0],S[1])<<'\n';
            continue;
        }
        if(n==3){
            int a = num(S[0],S[1]) + num(S[2]);
            int b = num(S[0],S[1]) * num(S[2]);
            int c = num(S[1],S[2]) + num(S[0]);
            int d = num(S[1],S[2]) * num(S[0]);
            std::cout<<std::min(a,std::min(b,std::min(c,d)))<<'\n';
            continue;
        }

        int menor=100, menor2=100,index=-1,index2=-1;
        for(int i=0; i<(n-1); ++i){
            if(S[i]!='1') apenas1=0;
            if(S[i]=='0'){
                next=1;
                break;
            }
            if(menor>num(S[i])){
                menor=num(S[i]);
                index=i;
            }
            if(menor==num(S[i]) && ((S[index+1]>S[i+1] && S[i+1]!='1') || S[index+1]=='1'))
                index=i;
            if(S[i]>'1'){
                if(menor2>num(S[i])){
                    menor2=num(S[i]);
                    index2=i;
                }
                if(menor2==num(S[i]) && (S[index2+1]>S[i+1] || S[index2+1]=='1'))
                index2=i;
            }
        }
        
        if(next || S[n-1]=='0'){
            std::cout<<"0\n";
            continue;
        }

        if(apenas1){
            std::cout<<num(S[n-2],S[n-1])<<'\n';
            continue;
        }

        int sum=0;

        for(int i=0; i<n; ++i)
            if(S[i]!='1')
                sum+=num(S[i]);

        int aux=sum;
        if(menor==1)
            aux+=10;
        else aux+=(9*menor);

        if(S[index+1]=='1')
            aux++;
        
        if(S[index2+1]==1)
            sum++;

        if(menor==menor2)
            std::cout<<aux<<'\n';
        else std::cout<<std::min(aux,(sum+9*menor2))<<'\n';
    }

    return 0;
}
