// link : https://leetcode.com/problems/bulls-and-cows/description/

// Code
class Solution {
public:
    string getHint(string s, string g) {
        int bulls = 0, cows = 0;
        int n = s.size();
        unordered_map<char,int>mp_s;
        for(int i=0;i<n;i++){
            if(s[i] == g[i]){
                bulls++;
            }
            else{
                mp_s[s[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!=g[i] and mp_s[g[i]]>0){
                mp_s[g[i]]--;
                cows++;
            }
        }
        string st = to_string(bulls) + "A" + to_string(cows) + "B";
        return st;
    }
};
