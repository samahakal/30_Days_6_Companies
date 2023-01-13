class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&dungeon,int i,int j){
        if(i == n || j == m) return INT_MAX;

        if(i == n-1 and j == m-1){
            if(dungeon[i][j]<0){
                return 1-dungeon[i][j];
            }
            return 1;
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int a = solve(dungeon,i,j+1);
        int b = solve(dungeon,i+1,j);
        int k = min(a,b);
        if(dungeon[i][j] >= k){
            k = 1;
        }
        else{
            k = k-dungeon[i][j];
        }
        return dp[i][j] = k;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        dp.resize(n,vector<int>(m,INT_MAX));
        return solve(dungeon,0,0);
    }
};








class Solution {
public:
    int n,m;
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size();
        m = dungeon[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));

        dp[n][m-1] = 1;
        dp[n-1][m] = 1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int k = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                if(k<=0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = k;
                }
            }
        }
        return dp[0][0];
    }
};
