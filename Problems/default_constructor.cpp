#include<iostream>
using namespace std;

class Student{
    public:
        int age;
        string name;

        // default constructor
        Student(){
            age = 18;
            name = "Prashant";
        }
        void display(){
            cout<<"Student Name: "<<name<<endl;
            cout<<"Student Age: "<<age<<endl;
        }
};

int main(){
    Student s1;
    s1.display();

    return 0;
}