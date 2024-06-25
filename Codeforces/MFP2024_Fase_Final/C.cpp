// https://codeforces.com/group/9CNwiex6Ir/contest/530284/problem/C
// MFP 2024 Fase Final - C - Ciclismo

#include <bits/stdc++.h>

std::vector<int> divide (int A);

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int A,B;

    std::cin>>A>>B;

    std::vector<int> divisors (divide(A));
    std::sort(divisors.begin(),divisors.end(), std::greater<int>());

    for(int i=divisors.size()-1; i>=0; --i){
        if(A-divisors[i]<=B){
            std::cout<<divisors[i]<<'\n';
            break;
        }
    }

    return 0;
}

std::vector<int> divide (int A){
    std::vector <int> divisors;
    for(int i=1; i*i<=A; i++)
        if(A%i==0){
            divisors.push_back(i);
            divisors.push_back(A/i);
        }
    return divisors;
}
