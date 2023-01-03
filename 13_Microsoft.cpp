https://leetcode.com/problems/airplane-seat-assignment-probability/description/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        vector<double>dp(n);
        double sum = 1;
        dp[0] = 1;
        
        // dp[5] = dp[1]/5 + dp[2]/5 + dp[3]/5 + dp[4]/5

        for(double i=1;i<n;i++){
            dp[i] = sum/(i+1.0);
            sum += dp[i];
        }
        return dp[n-1];        
    }
};
