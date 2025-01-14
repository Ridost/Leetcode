class StockSpanner {
public:
    struct node{
        int price;
        int span;
    };
    vector<node> stack;
    StockSpanner() {
    }
    
    int next(int price) {
        if(stack.empty() || stack.back().price>price){
            node n  = {price,1};
            stack.push_back(n);
            return 1;
        }
        int temp = 1;
        while(stack.back().price<=price){
            node n= stack.back();
            stack.pop_back();
            temp += n.span;
            if(stack.empty()) break;
        }
        node n  = {price,temp};
        stack.push_back(n);
        return temp;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
