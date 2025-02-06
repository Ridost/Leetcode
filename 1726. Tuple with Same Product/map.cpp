class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        //map <int,int> freq;
        unordered_map<int,int> freq;
        freq.reserve(n*(n-1)/2);
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                int num = nums[i] * nums[j];
                freq[num] = freq[num] + 1;
            }
        }
        for(const auto& m :freq){
            int k =  m.second;
            ans += k*(k-1)*4; 
        }
        return ans;
    }
};
