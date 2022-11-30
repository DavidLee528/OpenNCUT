/*
 * @ Author: 李天昊
 * @ Description: 类型转换构造函数
 * @ Date: 20210109
 * @ E-mail: 13121515269@163.com
 */

/**
 * ·类型转换构造寒素
 *  目的：实现类型的自动转换
 *  特点：只有一个参数 / 不是复制构造函数
 */


#include<iostream>

using namespace std; 

class Complex {
    public:
        // 成员变量
        double real; 
        double imag; 
        // 成员函数
        // 类型转换构造函数
        Complex(int i) {
            cout << "IntConstructor called" << endl; 
            real = i; 
            imag = 0; 
        }
        Complex(double r, double i) {
            real = r; 
            imag = i; 
        }
}; 

int main() {
    // 调用构造函数
    Complex c1(7, 8); 
    // 调用类型转换构造函数
    // 注意这是初始化而非赋值
    Complex c2 = 12; 
    // 9被自动转换成一个临时Complex类型的对象
    c1 = 9; 
    cout << c1.real << ',' << c1.imag << endl; 
    return 0; 
}