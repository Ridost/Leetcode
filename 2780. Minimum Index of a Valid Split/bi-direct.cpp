class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> firstMap, secondMap;
        int n = nums.size();
        for (auto &num:nums){
            secondMap[num]++;
        }
        for(int i = 0;i<n;i++){
            int num = nums[i];
            secondMap[num]--;
            firstMap[num]++;
            if(firstMap[num]*2 > i+1 && secondMap[num]*2 >n-i-1){
                return i;
            }
        }
        return -1;
    }
};
