// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/?orderBy=most_votes

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mn = n;
        int mx = 0;
        for(auto it : right){
            mn = min(mn,it);
        }
        for(auto it : left){
            mx = max(mx,it);
        }

        return max(mx,n-mn);
    }
};
