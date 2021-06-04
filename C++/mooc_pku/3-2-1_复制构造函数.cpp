/*
 * @ Author: 李天昊
 * @ Description: 复制构造函数
 * @ Date: 20210109
 * @ E-mail: 13121515269@163.com
 */

#include<iostream>

using namespace std; 

class Complex {
    private:
        double real; 
        double imag; 
    public:
        Complex(const Complex & c) {
            real = c.real; 
            imag = c.imag; 
            cout << " [ Copy Constructor called ] " << endl; 
        }
}

int main() {

    // 调用缺省无参构造函数
    Complex c1; 
    // 调用缺省的复制构造函数，将c2初始化和c1一样
    Complex c2(c1); 

    return 0; 
}