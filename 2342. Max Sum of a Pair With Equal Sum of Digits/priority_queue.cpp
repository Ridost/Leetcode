class Solution {
public:
    int maximumSum(vector<int>& nums) {
        //vector<int,int> digits;
        priority_queue<int,vector<int>,greater<int>> min_heap[82];
        int ans = 0;
        for(int num:nums){
            int count = num;
            int sum = count%10;
            while(count/=10){
                sum += count%10;
            }
            //digits[sum].push_back(num);
            if(min_heap[sum].size()==2){
                if(num>min_heap[sum].top()){
                    min_heap[sum].pop();
                    int top2 = min_heap[sum].top()+num;
                    ans = max(ans,top2);
                    min_heap[sum].push(num);
                }
            }
            else if(min_heap[sum].size()==1){
                int top2 = min_heap[sum].top()+num;
                ans = max(ans,top2);
                min_heap[sum].push(num);
            }
            else min_heap[sum].push(num);
        }
        if(ans==0) return -1;
        else return ans;
    }
};
