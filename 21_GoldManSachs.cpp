https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ps = INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<cards.size();i++){
            if(!mp.count(cards[i])){
                mp[cards[i]] = i;
            }
            else{
                ps = min(ps,i-mp[cards[i]]+1);
                mp[cards[i]] = i;
            }
        }
        return ps == INT_MAX ? -1 : ps;
    }
};
