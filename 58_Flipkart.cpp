// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int n,m;

    vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int solve(vector<vector<int>>&grid,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0){
            return 0;
        }

        int ans = 1;
        grid[i][j] = 0;
        for(auto it : dir){
            int x = i + it.first;
            int y = j + it.second;
            ans += solve(grid,x,y);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    ans = max(ans,solve(grid,i,j));
                }
            }
        }
        return ans;
        
    }
};
