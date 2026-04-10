#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int temp = INT_MAX, dist = INT_MAX;

        if(n < 3) return -1;

        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    if(nums[i] == nums[j] && nums[i] == nums[k]) {
                        temp = abs(i - j) + abs(j - k) + abs(k - i);
                        dist = min(dist, temp);
                    }
                }
            }
        }

        if(dist == INT_MAX) return -1;
        return dist;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 1, 1, 3, 1};

    int result = sol.minimumDistance(nums);

    if(result == -1)
        cout << "No valid triplet found\n";
    else
        cout << "Minimum Distance: " << result << endl;

    return 0;
}