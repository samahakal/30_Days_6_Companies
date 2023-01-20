// https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // vector to store all indexes of each alphabetes
        vector<vector<int>>v(26);
        
        for(int i=0;i<s.length();i++){
            v[s[i]-'a'].push_back(i);
        }
        
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            int curr_index = -1;    
            bool check = true;
            
            // every char in words array            
            for(char c : words[i]){
                auto it = upper_bound(v[c-'a'].begin(),v[c-'a'].end(),curr_index);
                
                if(it==v[c-'a'].end()){
                    check = false;
                }
                else{
                    curr_index = *it;
                }
            }
            if(check){
                cnt++;
            }
        }
        return cnt;
    }
};
