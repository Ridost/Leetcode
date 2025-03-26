class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        int a0 = grid[0][0]%x;
        vector<int> dis;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                int num = grid[i][j];
                if(num%x!=a0) return -1;
                dis.push_back(num/x);
            }
        }
        sort(dis.begin(),dis.end());
        int mid = dis[m*n/2];
        int cnt = 0;
        for(int d:dis){
            cnt += abs(mid-d);
        }
        return cnt;
    }
};
