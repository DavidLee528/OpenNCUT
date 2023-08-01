#include <iostream>

using namespace std; 

class A {
public: 
    void f1(); 
    int i; 
protected: 
    void f2(); 
    int j; 
private: 
    int k; 
}; 

class B: public A {
public: 
    void f3(); 
protected: 
    int m; 
private: 
    int n; 
}; 

class C: public B {
public: 
    void f4() {
        // f1(); 
        // f2(); 
        // f3(); 
    }
private: 
    int p; 
}; 

int main() {
    A a1; 
    B b1; 
    C c1; 
    
    c1.f4(); 

    return 0; 
}