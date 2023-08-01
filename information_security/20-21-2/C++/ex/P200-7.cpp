/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210509
 * @ E-mail: 13121515269@163.com
 */
#include <iostream>

using namespace std; 

class A {
private: 
    int a; 
    int b; 
public: 
    A() {
        cout << "constructor A1 called. " << endl; 
        a = 0; b = 0; 
    }
    A(int i) {
        cout << "constructor A2 called. " << endl; 
        a = i; b = 0; 
    }
    A(int i, int j) {
        cout << "constructor A3 called. " << endl; 
        a = i; b = j; 
    }
    void Display() {
        cout << "a = " << a << " b = " << b; 
    }
}; 

class B: public A {
private: 
    int c; 
public: 
    B() {
        cout << "constructor B1 called. " << endl; 
        c = 0; 
    }
    B(int i): A(i) {
        cout << "constructor B2 called. " << endl; 
        c = 0; 
    }
    B(int i, int j): A(i, j) {
        cout << "constructor B3 called. " << endl; 
        c = 0; 
    }
    B(int i, int j, int k): A(i, j) {
        cout << "constructor B4 called. " << endl; 
        c = k; 
    }
    void Display1() {
        Display(); 
        cout << " c = " << c << endl; 
    }
}; 

int main() {
    B b1; 
    B b2(1); 
    B b3(1, 3); 
    B b4(1, 3, 5); 
    b1.Display1(); 
    b2.Display1(); 
    b3.Display1(); 
    b4.Display1(); 
    return 0; 
}