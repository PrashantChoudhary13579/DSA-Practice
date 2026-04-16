#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int q = queries.size();
        int n = nums.size();
        vector<int> ans(q, -1);

        for(int i = 0; i < q; i++){
            int idx = queries[i];
            int f = INT_MAX, b = INT_MAX;
            // Forward search
            int round = n;
            int j = idx + 1;

            while(round--){
                if((j % n) != idx && nums[j % n] == nums[idx]){
                    f = (j - idx + n) % n;
                    break;
                }
                j++;
            }
            if(f == INT_MAX) f = -1;

            // Backward search
            round = n;
            j = idx - 1;
            while(round--){
                int pos = (j + n) % n;
                if(pos != idx && nums[pos] == nums[idx]){
                    b = (idx - pos + n) % n;
                    break;
                }
                j--;
            }
            if(b == INT_MAX) b = -1;

            if(f == -1 && b == -1) ans[i] = -1;
            else if(f == -1) ans[i] = b;
            else if(b == -1) ans[i] = f;
            else ans[i] = min(f, b);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1,3,1,4,1,3,2};
    vector<int> queries = {0,3,5};
    vector<int> result = sol.solveQueries(nums, queries);

    // Output result
    cout << "Answer: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}