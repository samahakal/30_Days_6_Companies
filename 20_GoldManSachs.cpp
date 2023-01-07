https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,int>tail;
        
        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : nums){
            if(mp[it] == 0) continue;
            mp[it]--;

            if(tail[it-1]>0){
                tail[it-1]--;
                tail[it]++;
            }
            else if(mp[it+1]>0 && mp[it+2]>0){
                mp[it+1]--;
                mp[it+2]--;
                tail[it+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
