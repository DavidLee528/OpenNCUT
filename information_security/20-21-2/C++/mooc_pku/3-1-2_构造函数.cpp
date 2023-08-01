/*
 * @ Author: 李天昊
 * @ Description: 构造函数
 * @ Date: 20210109
 * @ E-mail: 13121515269@163.com
 */

/**
 *  构造函数 === 成员函数的一种
 *  特点 ：函数名字与类名相同，可以有参数，不能有返回值
 *  作用 ：对对象进行初始化，给成员变量赋初值
 *  一个类可以有多个构造函数，他们之间是重载关系
 */

#include<iostream>

using namespace std; 

class Complex {
    private:
        double real; 
        double imag; 
    public:
        Complex(double r = 0, double i = 0); 
        void Set(double r, double i); 
}; 
// 自定义构造函数
Complex::Complex(double r = 0, double i = 0) {
    real = r; 
    imag = i; 
}

void Complex::Set(double r, double i) {
    real = r; 
    imag = i; 
}


int main() {

    // 下面几种情形，构造函数被调用
    Complex c; 
    Complex *pc = new Complex; 

    return 0; 
}