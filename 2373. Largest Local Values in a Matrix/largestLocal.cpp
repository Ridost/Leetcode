#include <vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> largestLocal(vector<vector<int>>&grid){
        vector<vector<int>> ans;
        for(int i=0;i<grid.size()-2;i++){
            vector<int> temp;
            for(int j=0;j<grid.size()-2;j++){
                int max = 0;
                for(int p=i;p<i+3;p++){
                    for(int q=j;q<j+3;q++){
                        if(grid[p][q]>max){
                            max = grid[p][q];
                        }
                    }
                }
                temp.push_back(max);
            }  
            ans.push_back(temp);
        }
        return ans;
    }
};