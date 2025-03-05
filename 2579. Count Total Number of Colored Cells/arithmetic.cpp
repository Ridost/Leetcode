class Solution {
public:
    long long coloredCells(int n) {
        long long ans = n;
        return 2*ans*(ans-1)+1;
    }
};
