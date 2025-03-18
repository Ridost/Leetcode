class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int currentBits = 0;
        int start = 0;
        int n = 0;

        for(int end = 0;end<nums.size();++end){
            while((currentBits&nums[end])!=0){
                currentBits ^= nums[start];
                start++;
            }
            currentBits |= nums[end];
            n = max(n,end-start+1);
        }
        return n;
    }
};
