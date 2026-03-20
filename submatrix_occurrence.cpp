#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> store;

                for (int p = i; p < i + k; p++) {
                    for (int q = j; q < j + k; q++) {
                        store.push_back(grid[p][q]);
                    }
                }

                sort(store.begin(), store.end());
                store.erase(unique(store.begin(), store.end()), store.end());

                int mini = INT_MAX;

                for (int z = 1; z < store.size(); z++) {
                    mini = min(mini, abs(store[z] - store[z - 1]));
                }

                ans[i][j] = (store.size() <= 1 ? 0 : mini);
            }
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<vector<int>> grid = {{3,4,6},{1,2,5}};
    int k = 2;

    vector<vector<int>> res = s.minAbsDiff(grid, k);

    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}