// https://leetcode.com/problems/maximum-good-people-based-on-statements/description/
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        int n = statements.size();

        auto isvalid = [&](int mask){
            for(int i=0;i<n;i++){
                if(1 & mask>>i){
                    for(int j=0;j<n;j++){
                        int good = mask>>j & 1;
                        if((good and statements[i][j]==0) || (!good and statements[i][j]==1)){
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        for(int i=1;i<(1<<n);i++){
            if(isvalid(i)) ans = max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};
