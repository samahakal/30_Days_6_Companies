// https://leetcode.com/problems/destroying-asteroids/description/

Solution 1
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long m = mass;
        for(int i=0;i<asteroids.size();i++){
            if(m < asteroids[i]) return false;
            m += asteroids[i];
        }
        return true;
    }
};


Solution 2
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        return accumulate(a.begin(),a.end(),mass,[](int m,int a){
            return m<a ? 0 : min(100000,a+m);
        });
    }
};
