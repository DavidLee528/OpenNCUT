/*
 * @ Author: 李天昊
 * @ Description: 位运算
 * @ Date: 20210108
 * @ E-mail: 13121515269@163.com
 */
#include<iostream>
#include<cmath>

using namespace std; 

int main() {

    int var1 = 21 & 18; 

    // 与运算：两位均为1则结果为1
    // 把var2的低8位清零
    int var2 = 987654321 & 0xffffff00; 

    // 或运算：有一位为1则结果为1
    // 把var3的低8位置1
    int var3 = 987654321 | 0xff; 

    // 异或运算：相同为0，不同为1（不进位加法，半加运算）
    // 将var4的低8位取反
    int var4 = 987654321 ^ 0xff; 
    // 交换两个变量的值
    int var5 = 10; 
    int var6 = 20; 
    var5 = var5 ^ var6; 
    var6 = var6 ^ var5; 
    var5 = var5 ^ var6; 

    // 非运算
    int var7 = ~21; 

    // 左移运算符
    // 左移n位，等于乘以2^n，运算速度远小于乘法运算
    int var8 = 9 << 4; 

    // 右移运算符
    // 低位若溢出则丢弃
    // 右移n位，等于除以2^n，有可能除不尽
    int var10 = -25 >> 4;   





    cout << var8 << '==' << 9 * pow(2, 4) <<endl; 

    return 0;  

}