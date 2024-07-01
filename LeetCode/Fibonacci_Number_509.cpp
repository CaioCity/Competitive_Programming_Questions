// https://leetcode.com/problems/fibonacci-number/description/ 
// 509 - Fibonacci Number 

// Solução com DP
class Solution {
public:
    int fib(int n) {
        
        int F[n+3];
        F[0]=0; F[1]=1;

        if(n<2)
            return F[n];

        for(int i=2; i<=n; ++i)
            F[i]=F[i-1]+F[i-2];
        
        return F[n];
    }
};

// Solução seca
class Solution {
public:
    int fib(int n) {
        
        int a=0,b=1,c=0;

        if(!n) return 0;
        if(n==1) return 1;
        for(int i=1; i<n; ++i){
            c=a+b;
            a=b;
            b=c;
        }

        return c;
    }
};
