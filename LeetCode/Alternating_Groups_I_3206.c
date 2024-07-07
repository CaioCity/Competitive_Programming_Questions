// https://leetcode.com/problems/alternating-groups-i/description/
// 3206 - Alternating Groups I

int numberOfAlternatingGroups(int* colors, int tam) {
    int ans=0;
    --tam;

    if(colors[0]!=colors[1] && colors[1]==colors[tam])
        ++ans;
    if(colors[0]!=colors[tam] && colors[0]==colors[tam-1])
        ++ans;

    for(int i = 1; i<tam; ++i)
        if(colors[i-1]==colors[i+1] && colors[i-1]!=colors[i])
            ++ans;

    return ans;
}
