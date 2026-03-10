//  using the concept of pigeon principle/ binary search 
// using the two pointers appraoch 
#include<iostream>
#include<vector>
using namespace std;

class Approach3 {
public:
    int Duplicate(vector<int> &v){
        int n = v.size();
        int left = 1;
        int right = n - 1;
        int mid, c;

        while(left < right){
            mid = left + (right - left)/2;

            c = 0;
            for(int i = 0; i < n; i++){
                if(v[i] <= mid)
                    c++;
            }

            if(c > mid)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main(){
    vector<int> nums = {3,4,5,6,1,1};
    Approach3 a3;
    cout<<"Duplicate number is "<<a3.Duplicate(nums)<<endl;
    return 0;
}