class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,0);
        for(int i =n-1;i>=0;i--){
            long long get_i = (questions[i][1]+i+1>=n) ? questions[i][0] : questions[i][0] + dp[questions[i][1]+i+1];
            long long not_get_i = (i+1>=n) ? 0 : dp[i+1];
            dp[i] = max(get_i,not_get_i);
        }
        return dp[0];
    }
};
