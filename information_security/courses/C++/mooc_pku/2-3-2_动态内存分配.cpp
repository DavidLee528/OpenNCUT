/*
 * @ Author: 李天昊
 * @ Description: 利用new运算符实现动态内存分配
 * @ Date: 20210108
 * @ E-mail: 13121515269@163.com
 */
/**
 * 动态内存分配
 * 两个运算符：new delete
 */

#include<iostream>

using namespace std; 

int main() {
    // 利用new运算符申请一个整型变量大小的内存空间
    // 等价于
    // int pn = 5; 
    int *pn; 
    pn = new int; 
    *pn = 5; 

    // 利用new运算符申请一个整型数组
    int i = 5; 
    int *pa; 
    pa = new int[i * 20];   // 可以容纳100个整型数据
    pa[0] = 123; 

    // 利用delete运算符释放不需要的内存
    // syntax : delete pointer'; （pointer必须指向new出来的空间）
    int *pi = new int; 
    *pi = 5; 
    delete pi; 
    // delete pi; (导致异常。一片空间不能被delete多次)
    // delete一个动态分配的数组
    delete [] pa; 



    return 0; 
}