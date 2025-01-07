// binary search
class Solution {
public:
    bool canEatInTime(vector<int> &piles,int k,int h){
        long hours=0;
        for(int pile:piles){
            int div = pile / k;
            hours += div;
            if(pile % k !=0) hours++;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left  = 1;
        int right =  *max_element(piles.begin(),piles.end());
        while(left <= right){
            int mid = left + (right-left)/2;
            if(canEatInTime(piles,mid,h)) right = mid -1;
            else left = mid + 1;
        }
        return left;
    }
};
