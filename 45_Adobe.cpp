// https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

class Solution {
public:

    int solve(vector<string>&nums,int a,int b){
        vector<pair<string,int>>v;
        int i = 0;
        for(auto it : nums){
            int n = it.size();
            string s = it.substr(n-b);
            v.push_back({s,i});
            i++;
        }
        sort(v.begin(),v.end());
        return v[a-1].second;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;

        int n = queries.size();
        int i = 0;
        while(i<n){
            ans.push_back(solve(nums,queries[i][0],queries[i][1]));
            i++;
        }
        return ans;
    }
};
