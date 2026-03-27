// Leet code problem - 2946: Matrix similarity after cyclic shifts

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void left_rotate(vector<vector<int>> &mat, int row, int n){
        int temp = mat[row][0];
        for(int i = 0; i < n - 1; i++){
            mat[row][i] = mat[row][i + 1];
        }
        mat[row][n - 1] = temp;
    }

    void right_rotate(vector<vector<int>> &mat, int row, int n){
        int temp = mat[row][n - 1];
        for(int i = n - 1; i > 0; i--){
            mat[row][i] = mat[row][i - 1];
        }
        mat[row][0] = temp;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k % n;
        vector<vector<int>> vec = mat;

        for(int i = 0; i < k; i++){
            for(int row = 0; row < m; row++){
                if(row % 2 == 0){
                    left_rotate(vec, row, n);
                } else {
                    right_rotate(vec, row, n);
                }
            }
        }

        return vec == mat;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}};
    int k = 2;

    if(sol.areSimilar(mat, k)) cout << "true";
    else cout << "false";

    return 0;
}