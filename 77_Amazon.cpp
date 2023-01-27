// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int inf = 1e8;

    int dp[101][101];

    int dfs(vector<pair<int,int>>adj[],int src,int dst,int k){
        if(k<0) return inf;

        if(src == dst) return 0;

        if(dp[src][k] != -1) return dp[src][k];

        int ans = inf;
        for(auto it : adj[src]){
            ans = min(ans,dfs(adj,it.first,dst,k-1)+it.second);
        }
        return dp[src][k] = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        memset(dp,-1,sizeof(dp));

        int ans = dfs(adj,src,dst,k+1);

        return ans == inf ? -1 : ans;
    }
};
