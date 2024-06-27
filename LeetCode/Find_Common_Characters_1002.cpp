// https://leetcode.com/problems/find-common-characters/
// 1002 - Find Common Characters

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int tam=words.size();
        map<string,int> resp, aux;
        string S;

        for(char x='a'; x<='z'; x++){
            S=x;
            aux[S]=0;
        }
        
        for(auto x : words[0]){
            S=x;
            resp[S]++;
        }
            
        for(int i=1; i<tam; i++){
            for(auto x : words[i]){
                S=x;
                aux[S]++;
            }
                
            for( auto& [k,v] : aux ){
                resp[k]= resp[k]<v?resp[k]:v;
                v=0;
            }     
        }

        vector<string> answer;
        for(auto [a,b] : resp)
            while(b--)
                answer.push_back(a);
        
        return answer;        
    }
};
