// https://leetcode.com/problems/top-k-frequent-words/description/
class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string,int>mp;
        for(auto it : words){
            mp[it]++;
        }

        vector<pair<string,int>>v;
        for(auto it : mp){
            v.push_back({it.first,it.second});
        }
        auto cmd = [&](pair<string,int>&a,pair<string,int>&b){
            if(a.second == b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        };
        sort(v.begin(),v.end(),cmd);
        vector<string>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
