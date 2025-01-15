class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -99999;
        int sell = 0;
        for(int price:prices){
            buy = max(buy,sell-price);
            sell = max(sell,buy+price-fee);
        }
        return sell;
    }
};
