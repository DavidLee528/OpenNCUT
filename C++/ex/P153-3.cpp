/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210505
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

class CComplex {
private: 
    double m_real; 
    double m_imag; 
public: 
    CComplex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag) {  }
    friend CComplex operator+(const CComplex &lhs, const CComplex &rhs); 
    void print_value() {
        cout << m_real << " + " << m_imag <<"i " << endl; 
    }
}; 

CComplex operator+(const CComplex &lhs, const CComplex &rhs) {
    return CComplex(lhs.m_real + rhs.m_real, lhs.m_imag + rhs.m_imag); 
}

int main() {

    CComplex c1(1, 2); 
    CComplex c2(3, 4); 
    CComplex c3; 
    int num = 5; 
    
    c3 = c1 + c2; 
    c3.print_value(); 

    c3 = num + c2; 
    c3.print_value(); 

    c3 = c1 + num; 
    c3.print_value(); 

    return 0; 
}