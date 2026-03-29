#include <iostream>
using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string s = s2;

        // already equal
        if (s1 == s2) return true;
        if (s[0] != s1[0]) {
            s[0] = s2[2];
            s[2] = s2[0];
        }
        if (s == s1) return true;

        // swap 1 and 3 if needed
        if (s[1] != s1[1]) {
            s[1] = s2[3];
            s[3] = s2[1];
        }
        if (s == s1) return true;
        return false;
    }
};

int main() {
    Solution obj;

    string s1, s2;

    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    if (obj.canBeEqual(s1, s2)) {
        cout << "Yes, strings can be made equal." << endl;
    } else {
        cout << "No, strings cannot be made equal." << endl;
    }

    return 0;
}