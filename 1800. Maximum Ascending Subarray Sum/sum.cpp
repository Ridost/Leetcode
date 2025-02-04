class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0],sub =nums[0];
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]<nums[i+1])sub += nums[i+1];
            else sub = nums[i+1];
            ans = max(ans,sub);
        }
        return ans;
    }
};
