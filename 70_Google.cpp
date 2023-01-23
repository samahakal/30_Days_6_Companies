// https://leetcode.com/problems/network-delay-time/description/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>val(n+1,10000);
        vector<int>vis(n+1,0);
        val[k] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        int N = n;
        int ans = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop(); 
            int _val = it.first;
            int _num = it.second;
            vis[_num] = 1;

            
            vis[_num] = 1;
            ans = _val;

            for(auto it : adj[_num]){
                if(vis[it.first]) continue;
                if(val[it.first] > it.second + _val){
                    val[it.first] = it.second + _val;
                    pq.push({val[it.first],it.first});
                }
            }
        }

        int mx = 0;
        for(int i=1;i<=n;i++){
            mx = max(mx,val[i]);
        }
        
        if(mx == 10000) return -1;
        return mx;
    }
};
