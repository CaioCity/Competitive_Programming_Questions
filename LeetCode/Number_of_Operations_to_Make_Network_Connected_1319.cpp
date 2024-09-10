// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
// 1319 - Number of Operations to Make Network Connected

class Solution {
public:
    int find(int A, int leader[]){
        if(A==leader[A]) return A;
        return leader[A] = find(leader[A],leader);
    }
    void join(int A,int B, int leader[],int conex[]){
        if(conex[A]>conex[B])
            std::swap(A,B);
        leader[B]=A;
        conex[A]+=conex[B];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int tam = connections.size();
        if(tam<(n-1)) return -1;
        int A,B,ans=0,leader[n],conex[n];
        for(int i=0; i<n; ++i){
            leader[i]=i;
            conex[i]=0;
        }
        for(int i=0; i<tam;++i){
            A = connections[i][0]; B = connections[i][1];
            A = find(A,leader); B = find(B,leader);
            if(A!=B)
                join(A,B,leader,conex);
        }
        
        unordered_set<int> S;
        for(int i =0; i<n; ++i)
            S.insert(find(leader[i],leader));
        return S.size()-1;
    }
};
