/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210313
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

void ReverseString(const string &str) {
    for_each(str.crbegin(), str.crend(), [](char c){ cout << c ; }); 
    cout << endl; 
}

void ManualReverseString(const string &_str) {
    string str(_str); 
    string::size_type sz = str.length(); 
    for (size_t i = 0; i < sz / 2; ++i) {
        char ch = str[i]; 
        str[i] = str[sz - i - 1]; 
        str[sz - i - 1] = ch; 
    }
    cout << str << endl; 
}

int main() {
    // ReverseString("hello"); 
    string s; 
    cin >> s; 
    ReverseString(s); 
    ManualReverseString(s); 
    return 0; 
}