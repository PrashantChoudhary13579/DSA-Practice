#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dist(int a, int b) {
        if (a == -1) return 0;
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        
        vector<int> dp(26, 0); // max saving
        int total = 0;
        
        for (int i = 1; i < n; i++) {
            int cur = word[i] - 'A';
            int prev = word[i - 1] - 'A';
            
            int d = dist(prev, cur);
            total += d;
            
            vector<int> new_dp = dp;
            
            for (int j = 0; j < 26; j++) {
                // try moving free finger from j -> cur
                new_dp[prev] = max(new_dp[prev], dp[j] + d - dist(j, cur));
            }
            
            dp = new_dp;
        }
        
        int max_save = 0;
        for (int x : dp) max_save = max(max_save, x);
        
        return total - max_save;
    }
};

int main() {
    Solution obj;

    string word;
    cout << "Enter word (uppercase letters only): ";
    cin >> word;

    int result = obj.minimumDistance(word);

    cout << "Minimum distance: " << result << endl;

    return 0;
}