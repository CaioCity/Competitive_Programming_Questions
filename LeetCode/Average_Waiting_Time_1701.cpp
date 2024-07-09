// https://leetcode.com/problems/average-waiting-time/description 
// 1701 - Average Waiting Time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int64_t ans = customers[0][1], time;
        int N = customers.size(), A, T;
        time=ans+customers[0][0];
        for(int i=1; i<N; ++i){
            A = customers[i][0], T = customers[i][1];
            if(time>A) time+=T;
            else time = A+T;
            ans+=(time-A);
        }
        #undef int
        return (ans*1.0)/N;
    }
};
