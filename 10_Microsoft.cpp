https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[n-1];
        int end = -1;
        int start = 0;

        for(int i=1;i<n;i++){
            if(mx<=nums[i]){
                mx = nums[i];
            }
            else{
                end = i;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i]<=mn){
                mn = nums[i];
            }
            else{
                start = i;
            }
        }
        return end-start+1;
    }
};
