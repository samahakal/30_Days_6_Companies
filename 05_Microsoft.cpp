// Link : https://leetcode.com/problems/largest-divisible-subset/description/


// time complexity : O(n^2)
// space complexity : O(n)


// code
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        
        // dp and res - > store index
        vector<int>dp(n,1),pre(n,-1);


        sort(nums.begin(),nums.end());

        int mx = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 and dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }

                if(dp[mx] < dp[i]){
                    mx = i;
                }
            }
        }

        vector<int>ans;

        int t = mx;
        while(t>=0){
            ans.push_back(nums[t]);
            t = pre[t];
        }
        return ans;
    }
};
