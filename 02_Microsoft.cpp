// link : https://leetcode.com/problems/combination-sum-iii/description/

// Code
class Solution {
public:
    vector<vector<int>>ans;

    void solve(int curr,vector<int>&v,int k,int sum){
        if(k == 0 and sum == 0){
            ans.push_back(v);
            return;
        }
        for(int i=curr;i<=9;i++){
            v.push_back(i);
            solve(i+1,v,k-1,sum-i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        solve(1,v,k,n);
        return ans;
    }
};
