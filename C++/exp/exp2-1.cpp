/*
 * @ Author: 李天昊
 * @ Description: 实验2-1
 * @ Date: 20210403
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <string>

using namespace std; 

class CStudent {
private: 
    string m_id; 
    double m_score; 
    static double sm_total_score; 
    static size_t sm_total_number; 
public: 
    CStudent() = default; 
    CStudent(const CStudent &s); 
    ~CStudent(); 

    inline void set_value(string id, double score); 
    inline string get_id(); 
    inline double get_score(); 
    inline static double get_average(); 
}; 

double CStudent::sm_total_score = 0; 
size_t CStudent::sm_total_number = 0; 

CStudent::CStudent(const CStudent &s): m_id(s.m_id), m_score(s.m_score) { 
    ++sm_total_number; 
    sm_total_score += s.m_score; 
}
CStudent::~CStudent() { 
    --sm_total_number; 
    sm_total_score -= m_score; 
}

inline void CStudent::set_value(string id, double score) {
    m_id = id; 
    m_score = score; 
    ++sm_total_number; 
    sm_total_score += m_score; 
}

inline string CStudent::get_id() {
    return m_id; 
}
 
inline double CStudent::get_score() {
    return m_score; 
}

inline double CStudent::get_average() {
    return sm_total_score / sm_total_number; 
}

int main() { 
    const int N = 5; 
    CStudent *stu = new CStudent[N]; 
    for (int i = 0; i < N; ++i) {
        string id; 
        double score; 
        cin >> id >> score; 
        (stu + i)->set_value(id, score); 
    }
    for (int i = 0; i < N; i += 2) {
        cout << " > The score of student " << (stu + i)->get_id() << " is " << (stu + i)->get_score() << ". " << endl; 
    }
    cout << " > The average score is " << CStudent::get_average() << ". " << endl; 
    delete [] stu; 
    return 0; 
}