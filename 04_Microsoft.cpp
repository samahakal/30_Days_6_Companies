// Link : https://leetcode.com/problems/rotate-function/description/

// Code
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        /
        int ans = INT_MIN;
        int curr = 0, sum = 0;  

        int n = nums.size();   

        for(int i=0;i<n;i++){
            curr += nums[i]*i;
            sum += nums[i];
        }

        for(int i=n-1;i>=0;i--){
            curr += sum - n*nums[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};
