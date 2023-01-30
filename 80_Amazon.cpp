// https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long>>mat(n+1,vector<long>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i+1][j+1] = mat[i+1][j] + mat[i][j+1] - mat[i][j] + grid[i][j];
            }
        }

        long ans = 0;
        for(int i=0;i+2<n;i++){
            for(int j=0;j+2<m;j++){
                ans = max(ans,mat[i+3][j+3] - mat[i][j+3] - mat[i+3][j] + mat[i][j] - grid[i+1][j]-grid[i+1][j+2]);
            }
        }
        return ans;
    }
};
