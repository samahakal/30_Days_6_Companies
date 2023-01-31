// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/description/

class Solution {
public:
    int mod = 1e9+7;
    unordered_map<long,unordered_map<long,long>>mp;

    int solve(int st,int en,int k){
        if(k<0) return 0;
        if(k == 0 and st == en) return 1;

        if(mp.count(st) and mp[st].count(k)) return mp[st][k];
        return mp[st][k] = (solve(st+1,en,k-1)%mod + solve(st-1,en,k-1)%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        return solve(startPos,endPos,k);
    }
};
