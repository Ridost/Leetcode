class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>> q;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,INT_MAX));
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push(make_pair(i,j));
                    height[i][j] = 0;
                }
            }
        }
        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int*direction:directions){
                int next_x = x+direction[0];
                int next_y = y+direction[1];
                if(next_x>=0 && next_x<m && next_y>=0 && next_y<n && height[next_x][next_y]>height[x][y]+1){
                    q.push(make_pair(next_x,next_y));
                    height[next_x][next_y] = height[x][y]+1;
                }
            }
        }
        return height;
    }
};
