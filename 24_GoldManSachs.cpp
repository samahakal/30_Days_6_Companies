https://leetcode.com/problems/ipo/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        
        priority_queue<int>pq;
        while(k--){
            while(v.size() and v.back().first<=w){
                pq.push(v.back().second);
                v.pop_back();
            }
            
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
