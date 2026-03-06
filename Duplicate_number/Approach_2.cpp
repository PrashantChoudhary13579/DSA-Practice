// Using the sorting function and then finding the duplicate element 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Approach2{
    public:
        int Duplicate_number(vector<int> & num){
            sort(num.begin(), num.end());
            for(int i=0 ; i<num.size(); i++){
                int j = i;
                int k = i+1;
                if (num[j] == num[k] ){
                    return num[j];
                }
            }
            return -1;
        }
};

int main(){
    vector<int> vec = {7,6,54,3,4,6};
    Approach2 a2;
    cout<<"Duplicate number from the array is "<<a2.Duplicate_number(vec)<<endl;
    return 0;
}