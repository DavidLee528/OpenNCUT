/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 
 * @ E-mail: 13121515269@163.com
 */

#include<iostream>

using namespace std; 

class Rectangle {
    private:
        // 成员变量
        int w; 
        int h; 
    public:
        // 成员函数
        void SetW(int w_); 
        void SetH(int h_); 
        int GetW(); 
        int GetH(); 
        int Area(); 
        int Perimeter(); 
        void Init(int w_, int h_); 
}; 

void Rectangle::SetW(int w_) {
    w = w_; 
}

void Rectangle::SetH(int h_) {
    h = h_; 
}

int Rectangle::GetW() {
    return w; 
}

int Rectangle::GetH() {
    return h; 
}

int Rectangle::Area() {
    return w * h; 
}

int Rectangle::Perimeter() {
    return 2 * (w + h); 
}

void Rectangle::Init(int w_, int h_) {
    w = w_; 
    h = h_; 
}


int main() {

    int w; 
    int h; 

    // 类定义的变量 ==> 类的实例 ==> 对象
    // 定义的过程 ：实例化
    // 不同的对象之间可以用 '=' 进行赋值
    Rectangle r; 


    r.Init(1, 1); 
    cin >> w >> h; 
    r.SetW(w); 
    r.SetH(h); 
    cout << "Area: " << r.Area() << endl; 
    cout << "Perimeter: " << r.Perimeter() << endl; 
    return 0; 
}
