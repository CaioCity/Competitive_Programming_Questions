// https://leetcode.com/problems/pass-the-pillow/description 
// 2582 - Pass the Pillow

int passThePillow(int n, int time) {
    time= time%((n-1)*2);
    if( time < n)
        return time+1;
    return 2*n - time -1;
}
