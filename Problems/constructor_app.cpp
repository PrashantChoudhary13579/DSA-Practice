#include<iostream>
#include<vector>
using namespace std;

class Test{
    public:
        int x;

        // constructor
        Test(int val){
            x = val;
        }
        // we put the value of val into x 
        void display(){
            cout<<"Value of x = "<<x <<endl;
        }
        void createObject(){
            Test obj(1);
            obj.display();
        }

};

int main(){
    Test t(5);
    t.display();
    return 0;
}