class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        char start = 1;
        char end = 1;
        for(int d:derived){
            if(d==1) end = end^1;
        }
        if(start==end) return true;
        return false;
    }
};
