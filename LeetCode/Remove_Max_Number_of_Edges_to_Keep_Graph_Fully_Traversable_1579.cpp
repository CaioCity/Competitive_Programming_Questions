// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable
// 1579 - Remove Max Number of Edges to Keep Graph Fully Traversable

class Solution {
public:
    int find( int A, int leader[]){
        int begin=A,next;
        while(leader[A]!=A)
            A=leader[A];

        while(begin!=A){
            next=leader[begin];
            leader[begin]=A;
            begin=next;
        }
        return A;
    }

    void unir(int A, int B, int leader[], int filhos[]){
        if(filhos[A]>filhos[B]){
            filhos[B]+=filhos[A];
            leader[A]=B;
        }
        else {
            filhos[A]+=filhos[B];
            leader[B]=A;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        int ans=0,auxans,count=0; 

        // Setup da DSU
        int leader[n+1],filhos[n+1], cpyleader[n+1],cpyfilhos[n+1];
        for(int i=0; i<=n; ++i){
            leader[i]=i;
            filhos[i]=1;
        }

        // Dividir arestas
        int tam=edges.size();
        queue<std::pair<int,int>> Alice, Bob, ambos;

        for(int i=0; i<tam; ++i){
            if(edges[i][0]==1)
                Alice.push({edges[i][1],edges[i][2]});
            else if(edges[i][0]==2)
                Bob.push({edges[i][1],edges[i][2]});
            else if(edges[i][0]==3)
                ambos.push({edges[i][1],edges[i][2]});
        }

        // Ambos
        int A,B;
        while(!ambos.empty()){
            if(count==(n-1))
                return ans+ambos.size()+Alice.size()+Bob.size();

            tie(A,B)=ambos.front();
            ambos.pop();
            A=find(A,leader), B=find(B,leader);

            if(A!=B){
                unir(A,B,leader,filhos); 
                ++count;
            }
            else ++ans;  
        }

        // Alice
        int cpycount=count;
        for(int i=0; i<=n; ++i){
            cpyfilhos[i]=filhos[i];
            cpyleader[i]=leader[i];
        }

        while(1){

            if(cpycount==(n-1))
                break;
            if(Alice.empty())
                return -1;

            tie(A,B)=Alice.front();
            Alice.pop();
            A=find(A,cpyleader), B=find(B,cpyleader);

            if(A!=B){
                unir(A,B,cpyleader,cpyfilhos); 
                ++cpycount;
            }
            else ++ans;  

        } ans+=Alice.size();
        
        // BoB

        while(1){

            if(count==(n-1))
                break;
            if(Bob.empty())
                return -1;

            tie(A,B)=Bob.front();
            Bob.pop();
            A=find(A,leader), B=find(B,leader);

            if(A!=B){
                unir(A,B,leader,filhos); 
                ++count;
            }
            else ++ans;  

        } ans+=Bob.size();
        
        return ans;

    }
};
