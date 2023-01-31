// https://leetcode.com/problems/number-of-matching-subsequences/description/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>v(26);
        int i = 0;
        for(auto it : s){
            v[it-'a'].push_back(i);
            i++;
        }

        int ans = 0;

        for(auto ss : words){
            int i = -1;
            bool flag = true;
            for(auto ch : ss){
                auto k = upper_bound(v[ch-'a'].begin(),v[ch-'a'].end(),i);
                if(k==v[ch-'a'].end()){
                    flag = false;
                    break;
                }
                i = *k;
            }
            if(flag) ans++;
        }
        return ans;
    }
};
