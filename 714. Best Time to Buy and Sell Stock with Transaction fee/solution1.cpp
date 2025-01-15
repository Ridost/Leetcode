class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int min = 99999;
        int n1 = 0;
        int gain = 0;
        for(int price:prices){
            if(min==99999){
                if(n1==0) min = price;
                else if(price<n1-fee) min = price;
                else if(price>n1){
                    gain += price-n1;
                    n1 = price;
                }
            }
            else if(price<min) min = price;
            else if(price-fee>min){
                gain += price-fee-min;
                min = 99999;
                n1 = price;
            }

        }
        return gain;
    }
};
