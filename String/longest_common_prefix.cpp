#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        
        int n = strs.size();
        string first = strs[0];
        string answer= "";

        for(int i=0;i < first.length(); i++){
            char ch = first[i];
            
            for(int j=1; j< n; j++){
                if(i >= strs[j].length() || strs[j][i] != ch) 
                return answer;
            }
            answer += ch;

        }
        
        return answer;
    }
};


int main(){

    Solution sol;
    vector<string> v = {"flower","flow","flying"};
    
    string answer = sol.longestCommonPrefix(v);
    cout<<"The common prefix - "<<answer<<endl;
    
    return 0;
}