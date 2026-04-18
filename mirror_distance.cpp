#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int n){
        int r = 0;
        int d = 0;
        while(n != 0){
            r = n % 10;
            n = n / 10;
            d = d * 10 + r;
        }
        return d;
    }

    int mirrorDistance(int n) {
        int r = reverseNum(n);
        return abs(r - n);
    }
};

int main() {
    Solution obj;
    
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = obj.mirrorDistance(n);
    
    cout << "Mirror Distance: " << result << endl;

    return 0;
}