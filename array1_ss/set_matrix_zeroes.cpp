// Using 2 marker array
// TC - O(m*n)
// SC - O(m+n)

// 0 - means False, 1- means True

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Approach1{
    public:
        void setmatrix(vector<vector<int>> &mat){

            int m = mat.size();
            int n = mat[0].size();

            vector<int> row(m,0);
            vector<int> col(n,0);

            // add the marker
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(mat[i][j] == 0){
                        row[i] =1;
                        col[j] =1;
                    }
                }
            }

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(row[i] || col[j]){
                        mat[i][j] =0;
                    }
                }
            }

        }
        void print(vector<vector<int>> mat, int m, int n){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cout<<mat[i][j]<<" | ";
                }
                cout<<endl;
            }
        }
};


int main(){

    vector<vector<int>> mat = {{1,4,0},{3,4,7},{0,3,5}};

    Approach1 A1;
    cout<<"Before matrix: "<<endl;
    A1.print(mat,3,3);
    cout<<"After matrix: "<<endl;
    A1.setmatrix(mat);
    A1.print(mat,3,3);

    return 0;   

}