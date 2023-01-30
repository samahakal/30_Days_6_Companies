// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

class Solution {
public:

    int ans = 0;

    void dfs(string &s,int ind,unordered_map<string,int>&mp,int k){
        if(ind == s.size()){
            ans = max(ans,k);
            return;
        }

        string curr = "";      
        for(int i=ind;i<s.size();i++){
            curr += s[i];

            if(mp[curr]>0){
                continue;
            }
            else{
                mp[curr]++;
                dfs(s,i+1,mp,k+1);
                mp[curr]--;
            }
        }       
    }

    int maxUniqueSplit(string s) {
        unordered_map<string,int>mp;
        dfs(s,0,mp,0);
        return ans;
    }
};
