// Here comes the first approach - by applying nested loop

#include<iostream>
#include<vector>
using namespace std;

class Approach1{
public:
    int Duplicate(vector<int> & arr){
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(arr[i] == arr[j]){
                    return arr[i];
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> v = {2,3,4,5,6,8,9,1,2};
    Approach1 a;
    int dup = a.Duplicate(v);
    cout<<"Hence the duplicate number in the array is "<<dup<<endl;

    return 0;
}