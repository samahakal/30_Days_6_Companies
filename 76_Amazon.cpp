// https://leetcode.com/problems/shuffle-an-array/description/

class Solution {
public:
    vector<int>v;
    vector<int>st;
    Solution(vector<int>& nums) {
        v = nums;
        st = nums;
    }
    
    vector<int> reset() {
        st = v;
        return v;
    }
    
    vector<int> shuffle() {
        int si = v.size();
        for(int i=si-1;i>=0;i--){
            int k = rand()%si;
            swap(st[k],st[i]);
            si--;
        }
        return st;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
