// Approach 2 - Optimal solution / interview fav.

// Time = O (m*n)
// Space = O (1)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Approach2{
    public:
        void setmatrix(vector<vector<int>> &matrix){
            int m = matrix.size();
            int n = matrix[0].size();

            bool firstrow = false;
            bool firstcol = false;

            for(int i=0; i<m; i++){
                if(matrix[i][0]==0) firstcol = true;
            }
            for(int j=0; j<n; j++){
                if(matrix[0][j] ==0) firstrow = true;
            }

            for(int i=1; i<m; i++){
                for(int j=1; j<n; j++){
                    if( matrix[i][j] == 0){
                        matrix[i][0] =0;
                        matrix[0][j] =0;
                    }
                }
            }
            for(int i=1; i<m; i++){
                for(int j=1 ;j<n;j++){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
            if(firstcol){
                for(int i=0; i<m; i++){
                    matrix[i][0] = 0;
                }
            }
            if(firstrow){
                for(int j=0; j<n; j++){
                    matrix[0][j] = 0;
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

    Approach2 A2;
    cout<<"Before matrix: "<<endl;
    A2.print(mat,3,3);
    cout<<"After matrix: "<<endl;
    A2.setmatrix(mat);
    A2.print(mat,3,3);

    return 0;   

}