// https://leetcode.com/problems/restore-ip-addresses/description/

class Solution {
public:
    int n;
    vector<string>ans;

    void dfs(string &s,int ind,string curr,int k){
        if(k>4) return;
        if(ind == n){
            if(k == 4){
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }

        dfs(s,ind+1,curr+s[ind]+'.',k+1);
        if(s[ind] == '0') return;

        if(ind+1<n){
            string ss = s.substr(ind,2);
            dfs(s,ind+2,curr+ss+'.',k+1);
        }

        if(ind+2<n){
            string ss = s.substr(ind,3);
            if(ss<="255"){
                dfs(s,ind+3,curr+ss+'.',k+1);
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        dfs(s,0,"",0);
        return ans;
    }
};
