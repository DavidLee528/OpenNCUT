/*
 * @ Author: 李天昊
 * @ Description: 函数缺省参数
 * @ Date: 20210108
 * @ E-mail: 13121515269@163.com
 */

/**
 * 函数缺省参数
 * 定义函数时可以让最右边连续若干个参数有缺省值（默认值）
 * 调用函数的时候，若相应位置不写参数，则参数默认为缺省值
 * 函数参数可缺省的目的在于提高程序的可扩充性
 */

#include<iostream>

using namespace std; 

/**
 * @brief 这是一个函数，用于练习函数缺省值
 * 
 * @param x1 第一个参数
 * @param x2 第二个参数，缺省值为2
 * @param x3 第三个参数，缺省值为3
 */
void func(int x1, int x2 = 2, int x3 = 3) {
    cout << x1 << endl << x2 << endl << x3 << endl; 
}

int main() {
    func(1); 
    func(1, 1); 
    func(1, 1, 1); 
    return 0; 
}