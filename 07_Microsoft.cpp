// https://leetcode.com/problems/course-schedule/description/

// Topological Sort 
// TC : O(n) and SC : O(n)


// BFS

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        
        
        
        
        
        // adj vector
        vector<int>adj[n];
        for(int i=0;i<e;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        
        // cnt indegree for all nodes
        vector<int>indegree(n,0);
        
        for(int i=0;i<e;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            indegree[v]++;
        }
        
        
        // bfs (kahn's algorithm)
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        // total possible topologycal sort member
        int cnt = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        // topological sort -> it is a linear ordering of nodes/indeces such that if there exit one edge between 2 nodes u and v ( u->v) then u apper before v, this work only on DFG (Directed Acyclic Graph) not give all member if it is cyclic graph
        
        // acyclic graph
        if(cnt == n){
            return true;
        }
        
        
        // cyclic graph       
        return false;

    }
};





// DFS

class Solution {
public:

    bool dfs(vector<int>adj[],vector<bool>&vis,vector<bool>&dfs_vis,int node){
        if(dfs_vis[node]) return false;
        if(vis[node]) return true;
        vis[node] = dfs_vis[node] = true;

        for(auto it : adj[node]){
            if(!dfs(adj,vis,dfs_vis,it)) return false;
        }

        dfs_vis[node] = false;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        vector<bool>vis(n,0);
        vector<bool>dfs_vis(n,0);

        for(auto it : pre){
            adj[it[0]].push_back(it[1]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!dfs(adj,vis,dfs_vis,i)){
                    return false;
                }
            }
        }
        return true;
    }
};






