class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(n==1) return 0;
        long long N1 = 0;
        long long N2 = 0;
        for(int i = 1;i<n;i++){
            N1 += grid[0][i];
        }
        long long m = N1;
        for(int i = 1;i<n;i++){
            N1 -= grid[0][i];
            N2 += grid[1][i-1];
            m = min(m,max(N1,N2));
        }
        return m;
    }
};
