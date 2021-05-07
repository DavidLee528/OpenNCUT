/*
 * @ Author: 李天昊
 * @ Description: 实验2-3
 * @ Date: 20210403
 * @ E-mail: 13121515269@163.com
 */

#define NDEBUG
#include <iostream>
#include <cmath>

using namespace std; 

class CPoint {
private: 
    double m_x; 
    double m_y; 
public: 
    CPoint() = default; 
    CPoint(double x, double y); 
    ~CPoint(); 

    double pdistance(const CPoint &p); 
    friend double cdistance(const CPoint &lhs, const CPoint &rhs); 
}; 

CPoint::CPoint(double x, double y): m_x(x), m_y(y) {  }
CPoint::~CPoint() {  }

double CPoint::pdistance(const CPoint &p) {
    return sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2)); 
}

double cdistance(const CPoint &lhs, const CPoint &rhs) {
    return sqrt(pow((lhs.m_x - rhs.m_x), 2) + pow((lhs.m_y - rhs.m_y), 2)); 
}

int main() {

    #ifndef NDEBUG
    CPoint p1(0, 0); 
    CPoint p2(3, 4); 
    if ((p1.pdistance(p2) - cdistance(p1, p2) < 1e-6) && p1.pdistance(p2) == 5) cout << "[ TEST OK ] distance = " << p1.pdistance(p2) << endl; 
    else cout << "[ TEST FAIL ]" << endl; 
    return 0; 
    #endif

    double x1, y1; 
    cout << "Enter x1 y1: "; 
    cin >> x1 >> y1; 
    cout << endl; 
    CPoint p1(x1, y1); 

    double x2, y2; 
    cout << "Enter x2 y2: "; 
    cin >> x2 >> y2; 
    cout << endl; 
    CPoint p2(x2, y2); 

    cout << "Distance between two points: " << p1.pdistance(p2) << endl; 


    return 0; 
}

