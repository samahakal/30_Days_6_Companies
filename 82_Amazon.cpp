// https://leetcode.com/problems/dota2-senate/description/

# Complexity
- Time complexity:O(n)

- Space complexity:O(n)

# Code
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>r;
        queue<int>d;

        int i = 0;
        int n = senate.size();
        for(auto it : senate){
            if(it == 'R') r.push(i);
            else d.push(i);
            i++;
        }


        while(!r.empty() && !d.empty()){
            if(r.front() < d.front()){
                d.pop();
                r.push(r.front()+n);
                r.pop();
            }
            else{
                r.pop();
                d.push(d.front() + n);
                d.pop();
            }
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};
