#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        long long mod = 1e9 + 7;
        int size = queries.size();

        for(int i = 0; i < size; i++){
            long long idx = queries[i][0];

            while(idx <= queries[i][1]){
                nums[idx] = (1LL * nums[idx] * queries[i][3]) % mod;
                idx += queries[i][2];
            }
        }

        long long output = 0;
        for(int i = 0; i < nums.size(); i++){
            output ^= nums[i];
        }

        return (int)output;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {780};
    vector<vector<int>> queries = {
        {0,0,1,13},
        {0,0,1,17},
        {0,0,1,9},
        {0,0,1,18},
        {0,0,1,16},
        {0,0,1,6},
        {0,0,1,4},
        {0,0,1,11},
        {0,0,1,7},
        {0,0,1,18},
        {0,0,1,8},
        {0,0,1,15},
        {0,0,1,12}
    };

    int result = sol.xorAfterQueries(nums, queries);

    cout << "Result: " << result << endl;

    return 0;
}