// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0];
        int mn = nums[n-1];
        int en = -1;
        int st = 0;


        for(int i=1;i<n;i++){
            if(mx<=nums[i]){
                mx = nums[i];
            }
            else{
                en = i;
            }
        }


        for(int i=n-2;i>=0;i--){
            if(mn>=nums[i]){
                mn = nums[i];
            }
            else{
                st = i;
            }
        }

        return en-st+1;
    }
};
