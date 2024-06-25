// https://leetcode.com/problems/flood-fill/description/
// Flood Fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //bfs
        int m=image.size(),n=image[0].size(),i,j;
        int inicial=image[sr][sc];

        queue<pair<int,int>> casas;
        casas.push({sr,sc});

        int mx[4]={1,0,-1,0};
        int my[4]={0,1,0,-1};

        while(!casas.empty()){ 
            i=casas.front().first;
            j=casas.front().second;
            casas.pop();
            
            if(image[i][j]==inicial && inicial!=color){
                image[i][j]=color;
                for(int k=0; k<4; k++)
                    if( (i+my[k])>=0 && (i+my[k])<m && (j+mx[k])>=0 && (j+mx[k])<n )
                        if(image[i+my[k]][j+mx[k]]==inicial)
                            casas.push({i+my[k],j+mx[k]});
            }          
        }                     
        return image;
    }
};
