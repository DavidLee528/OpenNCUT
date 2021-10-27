#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <functional>
#include <map>

using namespace std; 

/**
 * @description: Check for parenthesis matching
 * @param {const string&} Bracket array
 * @return {bool} Return true if str is an avaliable bracket array
 */
bool IsMatching(const std::string &str) {
    char head { str.at(0) }; 
    char tail { str.at(str.length() - 1) }; 
    if (head == ')' || head == ']' || head == '}') return false; 
    if (tail == '(' || tail == '[' || tail == '{') return false; 

    using CmpFunc_t = std::function<bool(char)>; 
    CmpFunc_t cmp_s = [](char opt) noexcept -> bool { return opt == ')'; }; 
    CmpFunc_t cmp_m = [](char opt) noexcept -> bool { return opt == ']'; }; 
    CmpFunc_t cmp_l = [](char opt) noexcept -> bool { return opt == '}'; }; 

    std::stack<char> s { }; 
    std::map<char, CmpFunc_t> check {{'(', cmp_s}, {'[', cmp_m}, {'{', cmp_l}}; 

    for (std::string::const_iterator iter = str.cbegin(); iter != str.cend(); ++iter) {
        if (*iter == '(' || *iter == '[' || *iter == '{') {
            s.push(*iter); 
            continue; 
        }
        if (check[s.top()](*iter)) {
            s.pop(); 
            continue; 
        } 
        return false; 
    }
    if (!s.empty()) return false; 

    return true; 
}

int main() {

    // TEST
    cout << (IsMatching("}{") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching(")(") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("][") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("[]") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("()") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("{}") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("{[()]}") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("{[)()]}") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("([]{})") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("({([])[]})") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("[))(){}") ? "[ O K ]" : "[ ERR ]") << endl; 
    cout << (IsMatching("[(]{)}") ? "[ O K ]" : "[ ERR ]") << endl; 

    return 0; 
}

