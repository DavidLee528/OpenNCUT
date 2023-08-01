/*
 * @ Author: 李天昊
 * @ Description: 
 * @ Date: 20210505
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <cstring>

using namespace std; 

class CMatrix {
private: 
    int mat[7]; 
public: 
    CMatrix(); 
    void set_mat(int *arr); 
    void display_mat(ostream &os = cout); 
    CMatrix operator+(const CMatrix &rhs); 
}; 

CMatrix::CMatrix() {
    memset(mat, 0, sizeof(mat) / sizeof(int)); 
}

void CMatrix::set_mat(int *arr) {
    for (int i = 0; i < 6; ++i) mat[i] = arr[i]; 
}

void CMatrix::display_mat(ostream &os) {
    for (int i = 0; i < 6; ++i) {
        os << mat[i] << " "; 
        if ((i + 1) % 3 == 0) os << endl; 
    }
}

CMatrix CMatrix::operator+(const CMatrix &rhs) {
    CMatrix tmp; 
    for (int i = 0; i < 6; ++i) {
        tmp.mat[i] = mat[i] + rhs.mat[i]; 
    }
    return tmp; 
}

int main() {

    int mat1[7] = { 
        1, 2, 3, 
        4, 5, 6
    }; 
    int mat2[7] = {
        2, 3, 4, 
        5, 6, 7
    }; 

    CMatrix m1; 
    CMatrix m2; 
    m1.set_mat(mat1); 
    m2.set_mat(mat2); 

    m1.display_mat(); cout << endl; 
    m2.display_mat(); cout << endl; 


    CMatrix m3; 
    m3 = m1 + m2; 
    m3.display_mat(); 


    return 0; 
}