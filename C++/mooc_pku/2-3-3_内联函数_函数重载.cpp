/*
 * @ Author: 李天昊
 * @ Description: 内联函数 函数重载 函数缺省参数
 * @ Date: 20210108
 * @ E-mail: 13121515269@163.com
 */

#include<iostream>

using namespace std; 

// 内联函数
// 函数体简单，使用内联函数减少函数调用的开销
// 空间换时间：可执行文件体积增大
inline int Max(int n1, int n2) {
    if (n1 > n2) return n1; 
    return n2; 
}

// 函数重载：名字相同，参数个数或参数类型不同
double Max(double n1, double n2) {
    if (n1 > n2) return n1; 
    return n2; 
}
int Max(int n1, int n2, int n3) {
    return (n1 > n2 ? n1 : n2) > n3 ? (n1 > n2 ? n1 : n2) : n3; 
}



int main() {
    cout << Max(1.1,111.1) << endl; 
    return 0; 
}



