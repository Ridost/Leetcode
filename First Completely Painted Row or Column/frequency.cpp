class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> table(m*n,make_pair(0,0));
        vector<int> f1(m,0);
        vector<int> f2(n,0);

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                table[mat[i][j]-1] = make_pair(i,j);
            }
        }
        for(int count=0;count<m*n;count++){
            int num = arr[count];
            int num_row = table[num-1].first;
            int num_col = table[num-1].second;
            f1[num_row] += 1;
            f2[num_col] += 1;
            if(f1[num_row]==n || f2[num_col]==m) return count;
        }
        return m*n-1;
    }
};
