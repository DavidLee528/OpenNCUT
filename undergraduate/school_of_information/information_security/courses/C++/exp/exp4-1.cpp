#include <iostream>

using namespace std; 

/* =========================================== */
/*            BASE CLASS - CShape              */
/* =========================================== */

class CShape {
public: 
    virtual double Area() = 0; 
    virtual double Length() = 0; 
    virtual void printArea() = 0; 
    virtual void printLength() = 0; 
    virtual void printInfo(CShape *rhs); 
}; 

void CShape::printInfo(CShape *rhs) {
    cout << "area: " << (*rhs).Area() << "  length: " << (*rhs).Length() << endl; 
}

/* =========================================== */
/*          DERIVED CLASS - CCircle            */
/* =========================================== */

class CCircle: public CShape {
private: 
    double r; 
    const double PI = 3.1415926; 
public: 
    CCircle(double _r): r(_r) {  }
    virtual double Area(); 
    virtual double Length(); 
    virtual void printArea(); 
    virtual void printLength(); 
}; 

double CCircle::Area() {
    return PI * r * r; 
}

double CCircle::Length() {
    return 2 * PI * r; 
}

void CCircle::printArea() {
    cout << " > Circle Area:   " << Area() << endl; 
}

void CCircle::printLength() {
    cout << " > Circle Length: " << Length() << endl; 
}

/* =========================================== */
/*          DERIVED CLASS - CSquare            */
/* =========================================== */

class CSquare: public CShape {
private: 
    double a; 
public: 
    CSquare(double _a): a(_a) {  }
    virtual double Area(); 
    virtual double Length(); 
    virtual void printArea(); 
    virtual void printLength(); 
}; 

double CSquare::Area() {
    return a * a; 
}

double CSquare::Length() {
    return 4 * a; 
}

void CSquare::printArea() {
    cout << " > Square Area:   " << Area() << endl; 
}

void CSquare::printLength() {
    cout << " > Square Length: " << Length() << endl; 
}

/* =========================================== */
/*        DERIVED CLASS - CRectangle           */
/* =========================================== */

class CRectangle: public CShape {
private: 
    double w; 
    double h; 
public: 
    CRectangle(double _w, double _h): w(_w), h(_h) {  }
    virtual double Area(); 
    virtual double Length(); 
    virtual void printArea(); 
    virtual void printLength(); 
}; 

double CRectangle::Area() {
    return w * h; 
}

double CRectangle::Length() {
    return 2 * (w + h); 
}

void CRectangle::printArea() {
    cout << " > Rectangle Area:   " << Area() << endl; 
}

void CRectangle::printLength() {
    cout << " > Rectangle Length: " << Length() << endl; 
}

void Show(CShape *rhs) {
    rhs->printInfo(rhs); 
}


int main() {

    CShape *pShape = nullptr; 

    // 圆
    pShape = new CCircle(123.456); 
    Show(pShape); 

    // 正方形
    pShape = new CSquare(123.456); 
    Show(pShape); 

    // 矩形
    pShape = new CRectangle(123.456, 234.567); 
    Show(pShape); 

    return 0; 
}
