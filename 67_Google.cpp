// https://leetcode.com/problems/k-divisible-elements-subarrays/description/

class trie{
    public:
    unordered_map<int,trie*>next;
    trie(){
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        trie *root = new trie();


        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int cnt = 0;
            trie *temp = root;

            for(int j=i;j<n;j++){
                if(nums[j]%p == 0){
                    cnt++;
                }
                if(cnt>k) break;

                if(!temp->next[nums[j]]){
                    temp->next[nums[j]] = new trie();
                    ans++;
                }
                temp = temp->next[nums[j]];
            }
        }
        return ans;
    }
};
