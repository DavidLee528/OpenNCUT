/*
 * @ Author: 李天昊
 * @ Description: 实验1-1
 * @ Date: 20210327
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>

using namespace std; 

class CTime { 

private: 
    int m_hour; 
    int m_minute; 
    int m_second; 
public: 
    CTime(int h = 0, int m = 0, int s = 0); 
    CTime(const CTime &t); 
    ~CTime(); 

    void set_time(int h, int m, int s) {
        m_hour = h; 
        m_minute= m; 
        m_second = s; 
    }
    inline void show_time() {
        cout << m_hour << ":" << m_minute << ":" << m_second << endl; 
    }
}; 

CTime::CTime(int h, int m, int s): m_hour(h), m_minute(m), m_second(s) {  }
CTime::CTime(const CTime &t): m_hour(t.m_hour), m_minute(t.m_minute), m_second(t.m_second) {  }
CTime::~CTime() {  }

int main() {
    
    CTime t1; 
    CTime t2(16, 43, 21); 
    t1.show_time(); 
    t2.show_time(); 
    t1.set_time(17, 44, 22); 
    t1.show_time(); 
    t2.show_time(); 
    
    return 0; 
}