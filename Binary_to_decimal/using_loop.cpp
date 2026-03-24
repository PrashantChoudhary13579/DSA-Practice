// Converting integer value of binary into decimal value.. 

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
    int num =  101101;
    int val = 0;
    int base = 1;
    int temp = num;
    while(temp){
        int rem = temp % 10;
        temp = temp /10;
        val += rem * base;
        base *= 2;
    }
    cout<<"Decimal value: "<<val<<endl;
    return 0;
}