#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending = nums[0];
        int result = nums[0];

        for(int i=1; i< nums.size(); i++){
            max_ending = max( nums[i], max_ending + nums[i]);

            result = max( result, max_ending);
        }
        return result;
    }
};

int main(){
    Solution s;

    vector<int> nums = {-4, -3, -7, -2, -10, -4};
    int sum = s.maxSubArray(nums);

    cout<<"Sum of the subset = "<<sum<<endl;

    return 0;
}