// https://leetcode.com/problems/swim-in-rising-water/description/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({grid[0][0],0,0});

        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0] = 1;

        vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            for(auto it : dir){
                int x = temp[1] + it.first;
                int y = temp[2] + it.second;

                if(x<0 || y<0 || x>=n || y>=m || vis[x][y]) continue;

                vis[x][y] = 1;
                if(x == n-1 and y == m-1){
                    return max(grid[x][y],temp[0]);
                }                
                pq.push({max(grid[x][y],temp[0]),x,y});
            }
        }    
        return 0;    
    }
};
