// https://leetcode.com/problems/min-cost-to-connect-all-points/
// 1584 - Min Cost to Connect All Points

// Questão sobre o algoritmo de Kruskal. Ainda desconhecia union find

class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {

        int tam=points.size();
        vector<tuple<int,int,int>> arestas;

        for(int i=1; i<=tam; i++)
            for(int j=i+1; j<=tam; j++){
                int x1=points[i-1][0], x2=points[j-1][0],y1=points[i-1][1],y2=points[j-1][1];
                arestas.push_back({(abs(x1-x2)+abs(y1-y2)),i,j});
            }
        
        sort(arestas.begin(), arestas.end());

        vector<int> cor_do_ponto (tam+1,0);
        vector<vector<int>> colors(1);
        int n_colors=0, answer=0, conect=0,index=0,n_retas=arestas.size();

        while( index<n_retas && conect<(tam-1) ){
            tuple<int,int,int> atual = arestas[index];
            index++;

            int p1=get<1>(atual), p2=get<2>(atual);

            if( cor_do_ponto[p1] == cor_do_ponto[p2] ){
                if( cor_do_ponto[p1] == 0 ){
                    colors.push_back(vector<int>());
                    int auxtam=colors.size()-1;
                    colors[auxtam].push_back(p1);
                    colors[auxtam].push_back(p2);
                    n_colors++;
                    cor_do_ponto[p1]=cor_do_ponto[p2]=n_colors;
                    answer+=get<0>(atual);
                    conect++;
                }
                else continue;
            }
            else if( cor_do_ponto[p1]==0 || cor_do_ponto[p2]==0){
                if(cor_do_ponto[p1]==0){
                    cor_do_ponto[p1]=cor_do_ponto[p2];
                    colors[cor_do_ponto[p1]].push_back(p1);
                }
                else {
                    cor_do_ponto[p2]=cor_do_ponto[p1];
                    colors[cor_do_ponto[p2]].push_back(p2);
                }
                    
                conect++;
                answer+=get<0>(atual);
            }
            else{
                //cores diferentes, hora do union find
                answer+=get<0>(atual);
                if(colors[cor_do_ponto[p1]].size() < colors[cor_do_ponto[p2]].size())
                    swap(p1,p2);
                for(auto i : colors[cor_do_ponto[p2]]){
                    cor_do_ponto[i]=cor_do_ponto[p1];
                    colors[cor_do_ponto[p1]].push_back(i);
                }
            }

        }
        
        return answer;

    }
};
