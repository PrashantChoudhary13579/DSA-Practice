#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        int ans = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;  // try to increase distance
            } else {
                i++;  // need smaller nums1[i]
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {55,30,5,4,2};
    vector<int> nums2 = {100,20,10,10,5};

    Solution obj;
    cout << obj.maxDistance(nums1, nums2) << endl;

    return 0;
}