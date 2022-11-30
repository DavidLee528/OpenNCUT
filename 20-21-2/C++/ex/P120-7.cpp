/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210419
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

class Student {
private: 
    int num; 
    float score; 
public: 
    Student(int n, float s): num(n), score(s) {  }
    void change(int n, float s) {
        num = n; 
        score = s; 
    }
    void display() {
        cout << num << " " << score << endl; 
    }
    void fun(Student &s) {
        s.display(); 
        s.change(101, 80.5); 
        s.display(); 
    }
}; 

int main() {

    Student stu(101, 78.5); 
    stu.fun(stu); 

    // Student stu(101, 78.5); 
    // const Student *p = &stu; 
    // p->display(); 
    // p->change(101, 80.5); 
    // p->display(); 

    return 0; 
}