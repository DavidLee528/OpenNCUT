/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210313
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

inline int Max(int n1, int n2, int n3 = 0) {
    return (((n1 > n2 ? n1 : n2) > n3) ? (n1 > n2 ? n1 : n2) : n3); 
}

int main() {
    cout << Max(111, 888) << endl; 
    cout << Max(333, 999, 1111) << endl; 
    return 0; 
}