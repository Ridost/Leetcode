#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int min = arr.size()/20;
        int max = arr.size()-min; 
        vector<int> ans(arr.begin()+min, arr.begin()+max);
        double sum = accumulate(ans.begin(),ans.end(),0.0);
        return sum/ans.size();
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10};
    cout<<s.trimMean(arr)<<endl;
    return 0;
}