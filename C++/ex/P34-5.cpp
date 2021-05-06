/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210306
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

int add(int x, int y); 

int main() {
    int a = 1; 
    int b = 2; 
    int c = add(a, b); 
    cout << "a + b = " << c << endl; 
    return 0; 
}

int add(int x, int y) {
    int z = x + y; 
    return z; 
}


// #include <iostream>

// using namespace std; 

// int main() {
//     int a, b; 
//     c = add(a, b)
//     cout << "a+b=" << c << endl; 
//     return 0; 
// }

// int add(int x, int y) {
//     z = x + y; 
//     retrun (z); 
// }