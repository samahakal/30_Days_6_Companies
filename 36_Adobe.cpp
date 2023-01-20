// https://leetcode.com/problems/knight-probability-in-chessboard/description/

class Solution {
private:
    vector<pair<int,int>>dir = {{1,2},{1,-2},{-1,-2},{-1,2},{2,1},{-2,1},{2,-1},{-2,-1}};
    unordered_map<int,unordered_map<int,unordered_map<int,double>>>dp;
public:
    double solve(int n,int k,int r,int c){
        if(r<0 || c<0 || r>=n | c>=n) return 0;
        if(k == 0) return 1;

        if(dp.count(r) and dp[r].count(c) and dp[r][c].count(k)) return dp[r][c][k];

        double ans = 0;
        for(auto it : dir){
            ans += solve(n,k-1,r+it.first,c+it.second);
        }
        return dp[r][c][k] = ans*0.125;
    }

    double knightProbability(int n, int k, int row, int column) {
        return solve(n,k,row,column);
    }
};
