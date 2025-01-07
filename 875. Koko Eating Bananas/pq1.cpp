class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        priority_queue<int> maxHeap(piles.begin(),piles.end());
        int n = maxHeap.size();
        int first = maxHeap.top();
        while(h>n){
            int m = maxHeap.top();
            maxHeap.pop();
            if(m==first/2 || m==first/2+1){
                maxHeap.pop();
                if(first%3==0){
                    maxHeap.push(first/3);
                    maxHeap.push(first/3);
                    maxHeap.push(first/3);
                }
                else if(first%3==1){
                    maxHeap.push(first/3+1);
                    maxHeap.push(first/3);
                    maxHeap.push(first/3);
                }
                else{
                    maxHeap.push(first/3+1);
                    maxHeap.push(first/3+1);
                    maxHeap.push(first/3);
                }
            }
            else if(m/2==1){
                maxHeap.push(m/2+1);
                maxHeap.push(m/2);
            }
            else{
                maxHeap.push(m/2);
                maxHeap.push(m/2);
            }
            n = maxHeap.size();
        }
        return maxHeap.top();
    }
};
