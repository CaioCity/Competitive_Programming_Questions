// https://leetcode.com/problems/redundant-connection/description/
// 684 - Redundant Connection

class Solution {
public:
    int find(int A, int leader[]){
        if(A == leader[A])
            return A;
        return leader[A] = find(leader[A],leader);
    }

    void join(int A, int B, int leader[], int conex[]){
        if(conex[A]>conex[B])
            swap(A,B);
        leader[B] = A;
        conex[A]+=conex[B];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        int *leader = (int*)malloc((N+4)*sizeof(int)), *conex = (int*)calloc(N+3,sizeof(int));
        int A,FA,B,FB,M = N+1;

        for(int i =0; i<=N; ++i)
            leader[i]=i;
        
        for(int i=0; i<M; ++i){
            A = edges[i][0]; B = edges[i][1];
            FA = find(A,leader); 
            FB = find(B,leader);
            if(FA==FB){
                std::vector<int> ans(2);
                ans[0] = A, ans[1] = B;
                return ans;
            }
            join(FA,FB,leader,conex);
        }
        return vector<int> (0);
    }
};
