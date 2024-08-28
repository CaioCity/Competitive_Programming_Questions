// https://leetcode.com/problems/number-of-provinces/description/
// 547 - Number of Provinces

class Solution {
public:
    int find(int A, int leader[]){
        if(A==leader[A])
            return A;
        return leader[A] = find(leader[A],leader);
    }

    void join(int A, int B, int leader[], int conex[]){
        if(conex[A]>conex[B])
            swap(A,B);
        leader[B] = A;
        conex[A]+=conex[B];
    }

    int findCircleNum(vector<vector<int>>& edges) {
        int a,b,N = edges.size();
        int *leader = (int*)malloc((N+5)*sizeof(int)), *conex = (int*)calloc(N+5,sizeof(int));   
        for(int i=0; i<N;++i)
            leader[i]=i;


        for(int i =0; i<N; ++i) 
            for(int j=i+1; j<N; ++j)
                if(edges[i][j]){
                    a = find(i,leader);
                    b = find(j,leader);
                    if(a!=b)
                        join(a,b,leader,conex);
                }

        unordered_set<int> S;
        for(int i=0; i<N; ++i)
            S.insert(find(i,leader));
        return ((int)S.size());
    }
};
