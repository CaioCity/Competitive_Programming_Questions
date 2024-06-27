// https://leetcode.com/problems/ipo/
// 502 - IPO

class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& lucro, vector<int>& custo) {
        vector<pair<int,int>> projects;
        int n =lucro.size(),index=0,count=0;
        for(int i=0; i<n; i++)
            projects.push_back({custo[i],lucro[i]}); // Lucro, numero do projeto

        sort(projects.begin(),projects.end());

        priority_queue<int> fila;
        
        while(count<k){
            cout<<index<<" w= "<<w<<'\n';
            while(index<n && projects[index].first<=w){
                fila.push(projects[index].second);
                index++;
            }
            if(!fila.empty()){
                w+=fila.top();
                fila.pop();
            } else return w;
            count++;
        }
        return w;
    }
};
