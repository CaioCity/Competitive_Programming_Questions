// https://leetcode.com/problems/xor-queries-of-a-subarray
// 1310 - XOR Queries of a Subarray

class Solution {
public:
    void built(int i_seg, int L, int R, vector<int>& arr, int seg[]){
        if(L==R)
            seg[i_seg] = arr[L-1];
        else {
            int mid = (L+R)>>1;
            built(i_seg<<1,L,mid,arr,seg);
            built((i_seg<<1)|1,mid+1,R,arr,seg);
            seg[i_seg] = seg[i_seg<<1] ^ seg[(i_seg<<1)|1];
        }
    }
    int query(int i_seg, int L, int R, int QL, int QR, int seg[]){
        if(QL>R || L>QR)
            return 0;
        if(QL<=L && R<=QR)
            return seg[i_seg];
        int mid = (L+R)>>1;
        return query(i_seg<<1,L,mid,QL,QR,seg) ^ query((i_seg<<1)|1,mid+1,R,QL,QR,seg);
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        std::vector<int> ans;
        int seg[(N+3)<<2];
        built(1,1,N,arr,seg);

        for(int i=0, tam = queries.size(); i<tam; ++i)
            ans.push_back(query(1,1,N,queries[i][0]+1,queries[i][1]+1,seg));
        return ans;
    }
};
