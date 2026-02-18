// Problem remain the same - we have to find out all the possible subset.
// But approach changes - now we are using the Backtracking

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void subset_problem(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res)
{
    if (index == arr.size())
    {
        res.push_back(temp);
        return;
    }

    else
    {
        // include
        temp.push_back(arr[index]);
        subset_problem(index + 1, arr, temp, res);

        // exclude
        temp.pop_back();
        subset_problem(index + 1, arr, temp, res);
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> temp;
    vector<vector<int>> res;

    subset_problem(0,arr,temp,res);

    for (int i=0; i< res.size(); i++){
        cout<<"[";
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j];
            if(j != res[i].size()-1) {
                cout<<",";
            }
        }
        cout<<"]"<<endl;
    }

    return 0;   
}