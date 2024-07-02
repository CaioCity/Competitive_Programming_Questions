// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// 0 - 1 Knapsack Problem

class Solution {
  public:
      int ans (int W, int N, int wt[], int val[], vector<vector<int>>& back){
          if(back[W][N]!=-1) return back[W][N];
          if(W == 0 || N == 0) return 0;
          if(W<wt[N-1]) return ans(W,N-1, wt, val, back);
          
          return back[W][N]=max(ans(W,N-1,wt,val,back),ans(W-wt[N-1],N-1,wt,val,back)+val[N-1]);
      }

      int knapSack(int W, int wt[], int val[], int N) { 
          vector<vector<int>> back (W+3, vector<int> (N+3,-1));
          return ans(W, N, wt, val, back);
      }
};
