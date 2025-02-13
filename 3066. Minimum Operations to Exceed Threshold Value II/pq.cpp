class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,std::greater<long>> pq;
        for(int num:nums) pq.push(num);
        int count = 0;
        while(pq.top()<k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            long res = 2*x + y;
            pq.push(res);
            count += 1;
        }
        return count;
    }
};
