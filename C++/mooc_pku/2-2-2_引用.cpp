/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */

#include<iostream>
using namespace std; 

int n = 0; 

void swap(int & a1, int & a2); 
int & SetValue(); 

int main() {
    // 引用型变量
    // double a = 4; 
    // double b = 5; 
    // double & r1 = a; 
    // double & r2 = r1; 
    // r2 = 10; 
    // cout << a << endl; 
    // r1 = b; 
    // cout << a << endl; 
    // cout << r2 << endl;  

    // 引用作为函数参数
    // int n1 = 3; 
    // int n2 = 4; 
    // swap(n1, n2); 
    // cout << n1 << ' ' << n2 << endl; 

    // 引用作为函数返回值
    cout << n << endl; 
    SetValue() = 100; 
    cout << n << endl; 

    return 0; 
}

void swap(int & a1, int & a2) {
    int tmp = a1; 
    a1 = a2; 
    a2 = tmp; 
}

int & SetValue() {
    return n; 
}

