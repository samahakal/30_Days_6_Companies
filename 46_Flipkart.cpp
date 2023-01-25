// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>dp((1<<n),-1);

        int tar = accumulate(nums.begin(),nums.end(),0);

        if(tar % k != 0 ) return false;

        tar /= k;

        dp[0] = 0;

        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask] == -1) continue;
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i)) && dp[mask] + nums[i] <= tar){
                    dp[mask|(1<<i)] = (dp[mask] + nums[i])%tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
};
