// https://leetcode.com/problems/generate-random-point-in-a-circle/description/

class Solution {
public:
    double x,y,r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    double _random(){
        return (double)rand()/RAND_MAX;
    }
    
    vector<double> randPoint() {
        vector<double>v;

        double len = sqrt(_random())*r;
        double deg = 2*M_PI*_random();

        v.push_back(x+len*cos(deg));
        v.push_back(y+len*sin(deg));
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
