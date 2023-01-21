// https://leetcode.com/problems/maximum-matrix-sum/description/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt = 0;
        int mn = INT_MAX;
        int n = matrix.size();

        long long sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mn = min(mn,abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    cnt++;
                }

                sum += abs(matrix[i][j]);
            }
        }

        if(cnt%2 == 0) return sum;
        return sum-2*mn;
    }
};
