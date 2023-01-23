// https://leetcode.com/problems/random-pick-with-weight/description/

class Solution {
public:
    vector<int>v;
    Solution(vector<int>& w) {
        int n = w.size();
        v.push_back(w[0]);
        for(int i=1;i<n;i++){
            v.push_back(v.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int index = rand()%(v.back());
        auto it = upper_bound(v.begin(),v.end(),index)-v.begin();
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
