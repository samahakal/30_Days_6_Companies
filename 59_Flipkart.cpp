// https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;

        for(auto it : s){
            mp[it]++;
        }     

        string ans = "";
        for(auto ch : order){
            if(mp[ch] > 0){
                string add(mp[ch],ch);
                ans += add;
                mp.erase(ch);
            }
        }

        for(auto it : mp){
            string add(it.second,it.first);
            ans += add;
        }
        return ans;
    }
};
