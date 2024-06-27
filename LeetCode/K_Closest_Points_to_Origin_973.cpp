// https://leetcode.com/problems/k-closest-points-to-origin/
// 973 - K Closest Points to Origin

int comparar(pair<int,int>& a, pair<int,int>& b){
    return (a.first*a.first + a.second*a.second) < (b.first*b.first + b.second*b.second);
}

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>> pontos;
        vector<vector<int>> ans;
        for(int a,b,i=0; i<points.size(); i++){
            a=points[i][0]; b=points[i][1];
            pontos.push_back({a,b});
        }
        sort(pontos.begin(),pontos.end(),comparar);
        for(auto [a,b] : pontos){
            cout<<a*a+b*b<<' ';
        }
        for(int i=0; i<k; i++){
            vector<int> aux;
            aux.push_back(pontos[i].first); aux.push_back(pontos[i].second);
            ans.push_back(aux);
        }
        return ans;
    }
};
