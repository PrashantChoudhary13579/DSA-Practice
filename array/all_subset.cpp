// Problem - find out all the possible subsets of an array

// Method 1: Bit Manipulation

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SubSet_Bitmap{
    public:
        vector<vector<int>> subset( vector<int> & arr, vector<vector<int>>& ans){
            for( int i=0 ; i < (1<< arr.size()) ; i++){ // finding all the subsets - upto 2^n it will go
                vector<int> sub;
                for(int j= 0 ;j < arr.size(); j++){
                    if( (i & (1<< j)) != 0){
                        sub.push_back(arr[j]);
                    }
                }

                ans.push_back(sub);
            }
            return ans;
        }
};

int main(){
    vector<int> arr = {1,2,3};
    
    vector<vector<int>> answer;

    SubSet_Bitmap back;
    back.subset( arr,answer);

    for (int i=0; i< answer.size(); i++){
        cout<<"[";
        for(int j=0; j<answer[i].size(); j++){
            cout<<answer[i][j];
            if(j != answer[i].size()-1) {
                cout<<",";
            }
        }
        cout<<"]"<<endl;
    }
    return 0;



    
}
