#include <bits/stdc++.h>  
#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int size = nums1.size() + nums2.size();
        vector<int> arr(size);

        int left = 0;
        int right = 0;
        int i = 0;

        // Merge both arrays
        while (left < nums1.size() && right < nums2.size()) {

            if (nums1[left] < nums2[right]) {
                arr[i++] = nums1[left++];
            } 
            else {
                arr[i++] = nums2[right++];
            }
        }

        // Copy remaining elements
        while (left < nums1.size()) {
            arr[i++] = nums1[left++];
        }

        while (right < nums2.size()) {
            arr[i++] = nums2[right++];
        }

        int n = size;

        // Find median
        if (n % 2 == 1)
            return arr[n / 2];
        else
            return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    }
};

int main() {

    Solution sol;

    // Example input
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};

    double result = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median = " << result << endl;

    return 0;
}
