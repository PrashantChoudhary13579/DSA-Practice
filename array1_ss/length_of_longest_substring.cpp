#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mp;   
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {

            if(mp.count(s[right]) && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }
            mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    
    Solution obj;    
    string s = "abcabcbb";
    cout << obj.lengthOfLongestSubstring(s);
    return 0;
}