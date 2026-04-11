#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1;

        unordered_map<int, vector<int>> mp;

        // store indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // check each value
        for(auto &it : mp) {
            vector<int> &v = it.second;

            if(v.size() < 3) continue;

            // check consecutive triples
            for(int i = 0; i + 2 < v.size(); i++) {
                int dist = 2 * (v[i+2] - v[i]);
                ans = min(ans, dist);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main() {
    Solution sol;

    // 🔹 Small example
    vector<int> nums = {1, 2, 1, 1, 3, 1};

    int result = sol.minimumDistance(nums);

    cout << "Minimum Distance: " << result << endl;

    return 0;
}