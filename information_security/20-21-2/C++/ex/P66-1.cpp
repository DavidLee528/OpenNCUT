/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

class Time {
private: 
    int hour_; 
    int minute_; 
    int second_; 
public: 
    void set_time(); 
    void show_time(); 
}; 

void Time::set_time() {
    cin >> this->hour_; 
    cin >> this->minute_; 
    cin >> this->second_; 
}

void Time::show_time() {
    cout << this->hour_ << ":" << this->minute_ << ":" << this->second_ << endl; 
}

int main() {
    // Time t; 
    Time *t = new Time(); 
    (*t).set_time(); 
    (*t).show_time(); 
    return 0; 
}