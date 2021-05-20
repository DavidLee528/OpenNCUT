/*
 * @ Author: 李天昊
 * @ Description: 实验3-1
 * @ Date: 20210427
 * @ E-mail: 13121515269@163.com
 */

#include <iostream>
#include <string>

using namespace std; 

class CPerson {
private: 
    string m_name;  // 姓名
    size_t m_age;   // 年龄
    string m_sex;   // 性别
public: 
    CPerson() = default; 
    CPerson(string name, size_t age, string sex): m_name(name), m_age(age), m_sex(sex) {  }
    inline void Display(ostream &os = cout); 
}; 

inline void CPerson::Display(ostream &os) {
    os << ">> name:  " << m_name << endl; 
    os << " | age:   " << m_age << endl; 
    os << " | sex:   " << m_sex << endl; 
}


class CStudent: public CPerson {
private: 
    size_t m_grade;     // 年级
    double m_score;     // 总学分
public: 
    CStudent(string name, size_t age, string sex, size_t grade, double score = 0): 
            CPerson(name, age, sex), m_grade(grade), m_score(score) {  }
    inline void Display(ostream &os = cout); 
    inline void add(double a); 

}; 

inline void CStudent::Display(ostream &os) {
    CPerson::Display(); 
    os << " | grade: " << m_grade << endl; 
    os << " | score: " << m_score << endl; 
}

inline void CStudent::add(double a) {
    m_score += a; 
}

int main() {
    CStudent stu("David Lee", 18, "male", 1, 10); 
    stu.Display(); 
    return 0; 
}
