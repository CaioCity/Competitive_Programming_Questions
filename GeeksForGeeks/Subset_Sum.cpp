// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Subset Sum Problem
// Observe o quao parecido é subset sum da knapsack. No lugar de apenas devolver o valor maximo, compare-o com a soma alvo.

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int N = arr.size();
        int DP[N+1][sum+1];
        
        for(int i=0; i<=N; ++i)
            DP[i][0] = 0;
        for(int i=0; i<=sum; ++i)
            DP[0][i] = 0;
        
        for(int item = 1; item<=N; ++item)
            for(int S = 1; S<=sum; ++S){
                if(S<arr[item-1])
                    DP[item][S] = DP[item-1][S];
                else{
                    int include = arr[item-1] + DP[item-1][S-arr[item-1]]; 
                    int exclude = DP[item-1][S];
                    DP[item][S] = max(include,exclude);
                }    
            }
            
        return DP[N][sum] == sum;
    }
};
