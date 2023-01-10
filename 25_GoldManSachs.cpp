// https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/
// O(n^2)
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



// O(n)
class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<ll>dp(n+1,0);
        dp[1] = 1;
        int share = 0, res = 0;
        for(int i=2;i<=n;++i){
            dp[i] = share = (share + dp[max(i-delay,0)] - dp[max(i-forget,0)] + mod)%mod;
        }
        for(int i=n-forget+1;i<=n;i++){
            res = (res+dp[i])%mod;
        }
        return res;
    }
};
