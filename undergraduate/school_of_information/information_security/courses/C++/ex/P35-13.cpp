/*
 * @ Author: 李天昊
 * @ Description: P35-13
 * @ Date: 20210313
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

void AscendingSort(const vector<int> &_iv) {
    vector<int> iv(_iv); 
    sort(iv.begin(), iv.end(), [](int lhs, int rhs) -> bool { return lhs < rhs; }); 
    for_each(iv.cbegin(), iv.cend(), [](int n) { cout << n << ' '; }); 
    cout << endl; 
}

void AscendingSort(const vector<float> &_fv) {
    vector<float> fv(_fv); 
    sort(fv.begin(), fv.end(), [](float lhs, float rhs) -> bool { return lhs < rhs; }); 
    for_each(fv.cbegin(), fv.cend(), [](float n) { cout << n << ' '; }); 
    cout << endl; 
}

void AscendingSort(const vector<double> &_dv) {
    vector<double> dv(_dv); 
    sort(dv.begin(), dv.end(), [](double lhs, double rhs) -> bool { return lhs < rhs; }); 
    for_each(dv.cbegin(), dv.cend(), [](double n) { cout << n << ' '; }); 
    cout << endl; 
}

int main() {
    vector<int> ivec {
        3, 1, 88, 7, 2000, 4321, 1, 0
    }; 
    vector<float> fvec {
        3.4, 1.1, 88.98, 7.12, 2000.37, 4321.82, 1.1, 0.3
    }; 
    vector<double> dvec {
        3.246216, 1.932748, 88.176613, 7.987641, 2000.000123, 4321.317651, 1.111111, 0.000003
    }; 
    AscendingSort(ivec); 
    AscendingSort(fvec); 
    AscendingSort(dvec); 
    return 0; 
}