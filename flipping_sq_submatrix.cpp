#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = 0; i < k / 2; i++){
            for(int j = 0; j < k; j++){
                swap(grid[x + i][y + j], grid[x + k - i - 1][y + j]);
            }
        }
        return grid;
    }
};

int main(){
    Solution s;

    vector<vector<int>> v = {
        {1,2,3,4},
        {13,14,15,8},
        {9,10,11,12},
        {5,6,7,16}
    };

    int x = 1;
    int y = 0;
    int k = 3;

    vector<vector<int>> result = s.reverseSubmatrix(v, x, y, k);

    for (auto &row : result){
        for(auto &val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}