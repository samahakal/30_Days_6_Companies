// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll>dp(n,0);
        dp[0] = 1;
        for(int i=0;i<n;i++){
            for(int j = i+delay;j<min(i+forget,n);j++){
                dp[j] = (dp[j]+dp[i])%mod;
            }
        }
        ll sum = 0;
        for(int i=n-forget;i<n;i++){
            sum = (sum + dp[i])%mod;
        }
        return sum;
    }
};
