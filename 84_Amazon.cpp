// https://leetcode.com/problems/most-popular-video-creator/description/

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        unordered_map<string,pair<string,long>>c_mx;
        unordered_map<string,long>mp;

        int n = c.size();
        long mx = 0;

        for(int i=0;i<n;i++){
            mp[c[i]] += views[i];
            if(c_mx.count(c[i]) == 0 || (c_mx[c[i]].second < views[i] ) || ( c_mx[c[i]].second == views[i] && c_mx[c[i]].first > ids[i])){
                c_mx[c[i]] = {ids[i],views[i]};
            }
            mx = max(mx,mp[c[i]]);
        }

        vector<vector<string>>v;
        for(auto it : mp){
            if(it.second == mx){
                v.push_back({it.first,c_mx[it.first].first});
            }
        }
        return v;
    }
};
