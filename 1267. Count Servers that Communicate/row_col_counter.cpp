class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);

        for(int i =0;i<m;i++){
            int row_count = 0;
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1) row_count += 1;
            }
            row[i] = row_count;
        }    

        for(int j =0;j<n;j++){
            int col_count = 0;
            for(int i = 0;i<m;i++){
                if(grid[i][j]==1) col_count += 1;
            }
            col[j] = col_count;
        }
        int total = 0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(row[i]>1 || col[j]>1){
                        total += 1;
                    }
                }
            }
        }
        return total;
    }
};
