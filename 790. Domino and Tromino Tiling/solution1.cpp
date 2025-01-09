class Solution {
public:
    int numTilings(int n) {
        long m = pow(10,9)+7;
        cout<<m;
        if(n==1) return 1;
        else if (n==2) return 2;
        vector<long long>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i<=n;i++){
            dp[i] = 2*dp[i-1] + dp[i-3];
            dp[i] %= m;
        }
        return dp[n]%m;
    }
};
