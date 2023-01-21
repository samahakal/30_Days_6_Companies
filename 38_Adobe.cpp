// https://leetcode.com/problems/minimum-genetic-mutation/

class Solution {
public:
    int diff(string a,string b){
        int cnt = 0;
        for(int i=0;i<8;i++){
            if(a[i]!=b[i]) cnt++;
        }
        return cnt;
    }
    int ans = 0;
    int solve(string st,string en,unordered_map<string,int>mp){
        if(st == en){
            return 0;
        }

        int ans = 100;

        for(auto it : mp){
            if(it.second == 0) continue; 
            if(diff(it.first,st) == 1){
                mp[it.first]--;
                ans = min(ans,1+solve(it.first,en,mp));
            }
        }
        return ans;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int>mp;
        for(auto it : bank){
            mp[it]++;
        }

        int k = solve(startGene,endGene,mp);
        if(k<100) return k;
        return -1;
    }
};
