// https://leetcode.com/problems/maximum-good-people-based-on-statements/description/
// O(2^n*n*n)

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();

        auto isValid = [&](int m){
            for(int i=0;i<n;i++){
                if(m>>i & 1){
                    for(int j=0;j<n;j++){
                        bool good = (m>>j & 1);
                        if((good and statements[i][j]==0) || (!good and statements[i][j]==1)){
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        int ans = 0;
        for(int i=1;i<(1<<n);i++){
            if(isValid(i)) ans = max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};
