// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Subset Sum Problem

class Solution{
  public:
  bool isSubsetSum(vector<int>arr, int sum){
        unordered_set<int> S;
        vector<int> V;
        int tam=arr.size();
        S.insert(0);
        
        for(int i=0; i<tam; ++i){
            for(auto j : S)
                V.push_back(j+arr[i]);
            while(!V.empty()){
                S.insert(V.back());
                V.pop_back();
            }
        }
        if(S.find(sum)!=S.end())
            return true;
        return false;
  }
};
