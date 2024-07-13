// https://atcoder.jp/contests/abc354/tasks/abc354_b
// AtCoder Janken 2

    #include <bits/stdc++.h>  

    using namespace std;

    int main(){

        int N,sum=0, aux;
        cin>>N;
        string S[N];

        for(int i=0; i<N; i++){
            cin>>S[i]>>aux;
            sum+=aux;
        }
        
        sort(S, S+N);

        std::cout<<S[sum%N]<<endl;

        return 0;
    }
