class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1 , dec = 1 , ans = 1;
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                dec += 1;
                inc = 1;
                ans = max(ans,dec);
            }
            else if(nums[i]<nums[i+1]){
                dec = 1;
                inc += 1;
                ans = max(ans,inc);
            }
            else{
                inc = 1;
                dec = 1;
            }
        }
        return ans;
    }
};
