#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // horizontal layer

        long long total = 0;
        for (auto& row : grid) {
            for (auto& x : row) {
                total += x;
            }
        }
        long long sum_up = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                sum_up += grid[i][j];
            }
        if (sum_up == total - sum_up)
            return true;
        }


        // vertical

        long long curr = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                curr += grid[i][j]; 
            }
            if (curr == total - curr)
                return true;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> v = {{1,5},{2,3}};
    Solution s;
    bool val = s.canPartitionGrid(v);
    cout<<"Will this vector can be partitioned ? " <<endl;
    cout<<"Answer - "<<val<<endl;
    return 0;
}