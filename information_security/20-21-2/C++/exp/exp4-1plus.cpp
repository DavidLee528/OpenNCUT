/**
 * Based on exp4-1.cpp: 
 *  - Support multi-shapes input
 *  - Added area sorting function
 *  - Added perimeter sorting function
 *  - Added new derived class CTriangle
 *  - Optimized display function
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std; 

const size_t MAX_SHAPE_SIZE = 100; 

/* =========================================== */
/*            BASE CLASS - CShape              */
/* =========================================== */

class CShape {
public: 
    virtual double Area() = 0; 
    virtual double Length() = 0; 
    virtual void printArea() = 0; 
    virtual void printLength() = 0; 
}; 

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

/* =========================================== */
/*         DERIVED CLASS - CTriangle           */
/* =========================================== */
class CTriangle: public CShape {
private: 
    double a; 
    double b; 
    double c; 
public: 
    CTriangle(double _a, double _b, double _c): a(_a), b(_b), c(_c) {  }
    virtual double Area(); 
    virtual double Length(); 
    virtual void printArea(); 
    virtual void printLength(); 
}; 

double CTriangle::Area() {
    double p = (a + b + c) / 2.0; 
    return sqrt(p * (p - a) * (p - b) * (p - c)); 
}

double CTriangle::Length() {
    return a + b + c; 
}

void CTriangle::printArea() {
    cout << " > Triangle Area:   " << Area() << endl; 
}

void CTriangle::printLength() {
    cout << " > Triangle Length: " << Length() << endl;
}

CShape *pShapes[MAX_SHAPE_SIZE]; 

int main() {

    // Data Size n
    int n; 
    cout << "> Enter Data Size: "; 
    cin >> n; 

    // Pointers Initialization
    CCircle *pCir; 
    CSquare *pSqr; 
    CRectangle *pRec; 
    CTriangle *pTri; 

    // Choose Data Type
    // Data Input
    for (int i = 0; i < n; ++i) {   
        cout << "> Enter Data Type(Circle[C], Square[S], Rectangle[R]), Triangle[T]: "; 
        char c; 
        cin >> c; 
        switch (c) {
            // C stands for circle
            case 'C':
                cout << "Input radius: "; 
                double radius; 
                cin >> radius; 
                pCir = new CCircle(radius); 
                pShapes[i] = pCir; 
                break;
            // S stands for square
            case 'S':
                cout << "> Input length: "; 
                double length; 
                cin >> length; 
                pSqr = new CSquare(length); 
                pShapes[i] = pSqr; 
                break;
            // R stands for rectangle
            case 'R':
                cout << "> Input width and height: "; 
                double width; 
                double height; 
                cin >> width >> height; 
                pRec = new CRectangle(width, height); 
                pShapes[i] = pRec; 
                break;
            // T stands for triangle
            case 'T': 
                cout << "> Input side length of triangle: "; 
                double a; 
                double b; 
                double c; 
                cin >> a >> b >> c; 
                pTri = new CTriangle(a, b, c); 
                pShapes[i] = pTri; 
                break; 
            default:
                cout << "> Invalid Character, Please Enter Again: " << endl; 
                --i; 
                continue; 
                break;
        }
    }

    // Choose sorting type
    // Sort array pShapes
    // Data Output
    cout << "Sort by Area[A] or Length[L]? "; 
    char c; 
    cin >> c; 
    switch (c) {
    // sort by area
    case 'A':
        sort(
            pShapes, pShapes + n, [](CShape *lhs, CShape *rhs) {
                return lhs->Area() < rhs->Area(); 
            }
        ); 
        break;
    // sort by length
    case 'L': 
        sort(
            pShapes, pShapes + n, [](CShape *lhs, CShape *rhs) {
                return lhs->Length() < rhs->Length(); 
            }
        ); 
        break; 
    // sort type error
    default:
        cout << "> Invalid Character, Please Enter Again: " << endl; 
        break;
    }

    // Data Output
    for (int i = 0; i < n; ++i) {
        if (c == 'A') pShapes[i]->printArea(); 
        if (c == 'L') pShapes[i]->printLength(); 
        // cout << endl; 
    }

    return 0; 
}
