// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

# Approach
<!-- Describe your approach to solving the problem. -->
1) find the route of bob
2) bfs on alice route

# Complexity
- Time complexity:O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
   
    vector<int>v;
    bool dfs(vector<int>adj[],int ind,vector<int>&vis){
        
        vis[ind] = 1;
        v.push_back(ind);
        
        if(ind == 0){
            return true;
        }
        
        for(auto it : adj[ind]){
            if(vis[it] == 0 and dfs(adj,it,vis)){
                return true;
            }
        }
        
        v.pop_back();
        return false;
    }
   
    
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        // graph
        vector<int>adj[n+1];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // find bob route
        vector<int>vis(n+1,0);
        dfs(adj,bob,vis);

        // for alice route
        vector<int>vis1(n+1,0);

        // bob route
        vector<int>vis2(n+1,0);

        int alice = 0;
        int ans = INT_MIN;
        int amt = 0;
        int len = 0;

        queue<vector<int>>q;
        q.push({0,0,0,0});

        // bob route
        for(auto it : v){
            vis2[it] = true;
        }        

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            amt = temp[0];
            alice = temp[1];
            bob = temp[2];
            len = temp[3];
            vis1[alice] = true;

            // check alice and bob on same route or not
            if(bob<v.size()){
                // both visited simultaneously
                if(alice == v[bob]){
                    amt += amount[alice]/2;
                }
                // bob already visited it
                else if(vis2[alice] and len >= (v.size())/2){
                    // ***** do nothing :) 
                }
                // alice visited first
                else{
                    amt += amount[alice];
                }
            }
            else{
                amt += amount[alice];
            }

            // to check curr node is a leaf node or not
            bool flag = true;
            for(auto it : adj[alice]){
                // already visited
                if(vis1[it]) continue;

                q.push({amt,it,bob+1,len+1});
                flag = false;
            }

            // leaf node
            if(flag){
                ans = max(ans,amt);
            }

        }
        return ans;        
    }
};
```
# upvote if it's help you HAPPY CODING :)
