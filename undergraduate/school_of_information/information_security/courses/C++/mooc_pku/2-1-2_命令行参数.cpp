/*
 * @ Author: 李天昊
 * @ Description: 命令行参数
 * @ Date: 20210108
 * @ E-mail: 13121515269@163.com
 */

#include<iostream>

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::cout << *(argv + i) << std::endl; 
    }
    return 0; 
}