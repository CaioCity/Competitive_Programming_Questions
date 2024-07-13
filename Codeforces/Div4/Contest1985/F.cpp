// https://codeforces.com/contest/1985/problem/F
// Final Boss

#include <bits/stdc++.h>

typedef std::pair<int64_t,int> duo;

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int H,N;
        int64_t time=1;
        std::cin>>H>>N;
        int damage[N], cd[N];
        for(int i=0; i<N; i++)
            std::cin>>damage[i];
           
        for(int i=0; i<N; i++)
            std::cin>>cd[i];

        std::priority_queue<duo, std::vector<duo>, std::greater<duo>> heap;
        for(int i=0; i<N; i++)
            heap.push({1,i});
        
        int a,b;
        while(H>0){
            time=heap.top().first;
            while(heap.top().first==time){
                std::tie(a,b)=heap.top();
                heap.pop();
                H-=damage[b];
                if(H<=0)
                    break;
                heap.push({time+cd[b],b});
            }
        }
    
        std::cout<<time<<'\n';
    }

    return 0;
}
