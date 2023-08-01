/*
 * @ Author: 李天昊
 * @ Description: 实验1-2
 * @ Date: 20210330
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

class CCircle {
private: 
    double m_radius; 
    const double PI = 3.14; 
public: 
    CCircle(double r); 
    CCircle(const CCircle &c); 
    ~CCircle(); 
    double length();  
    double area();  
}; 

CCircle::CCircle(double r) {
    if (r < 0) throw "Invalid Radius Value. "; 
    m_radius = r; 
}
CCircle::CCircle(const CCircle &c): m_radius(c.m_radius) {  }
CCircle::~CCircle() {  }
inline double CCircle::length() {
    return 2 * PI * m_radius; 
}
inline double CCircle::area() {
    return PI * m_radius * m_radius; 
}

int main() {
    CCircle c(10.0); 
    cout << "circumference: " << c.length() << endl; 
    cout << "area: " << c.area() << endl; 
    return 0; 
}