// https://leetcode.com/problems/n-th-tribonacci-number/
// 1137 - N-th Tribonacci Number

// Solução com DP
class Solution {
public:
    int tribonacci(int n) {        
        int F[n+3];
        F[0]=0; F[1]=1, F[2]=1;

        if(n<3)
            return F[n];

        for(int i=3; i<=n; ++i)
            F[i]=F[i-1]+F[i-2]+F[i-3];
        
        return F[n];
    }
};

// Solução seca
class Solution {
public:
    int tribonacci(int n) {
        
        int a=0,b=0,c=1,d=0;

        if(!n) return 0;
        if(n==1) return 1;
        for(int i=1; i<n; ++i){
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }

        return c;
    }
};
