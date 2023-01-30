// https://leetcode.com/problems/maximum-subarray-min-product/description/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long>dp(n+1,0);
        for(int i=0;i<n;i++){
            dp[i+1] = dp[i] + nums[i];
        }

        stack<long>st;

        long ans = 0;
        
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || nums[st.top()] > nums[i])){
                int j = st.top();
                st.pop();
                ans = max(ans,nums[j]*(dp[i] - dp[st.empty() ? 0 : st.top()+1]));
            }
            st.push(i);
        }
        int mod = 1e9+7;
        return ans%mod;        
    }
};
