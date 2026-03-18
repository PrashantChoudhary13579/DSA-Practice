#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                prefix[i][j] = grid[i][j];

                if(i > 0) prefix[i][j] += prefix[i-1][j];
                if(j > 0) prefix[i][j] += prefix[i][j-1];
                if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];

                if(prefix[i][j] <= k) count++;
            }
        }

        return count;
    }
};

int main(){
    vector<vector<int>> v = {{7,2,9},{1,5,0},{2,6,6}};
    Solution s;
    int count = s.countSubmatrices(v,20);
    cout<<"Total no. of such submatrices: "<<count<<endl;
    return 0;

}