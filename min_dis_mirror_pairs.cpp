#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minimumDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // value -> index
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            // Check if current number already exists
            if (mp.count(nums[i])) {
                ans = min(ans, i - mp[nums[i]]);
            }

            // Store reverse of current number
            int rev = reverseNum(nums[i]);
            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution sol;

    // Example test cases
    vector<int> nums1 = {12, 21, 45, 33, 54};
    vector<int> nums2 = {120, 21};
    vector<int> nums3 = {21, 120};

    cout << "Output 1: " << sol.minimumDistance(nums1) << endl;
    cout << "Output 2: " << sol.minimumDistance(nums2) << endl;
    cout << "Output 3: " << sol.minimumDistance(nums3) << endl;

    return 0;
}