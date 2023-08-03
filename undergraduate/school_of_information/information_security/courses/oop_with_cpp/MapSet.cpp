#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std; 

void UseMap() {
    // initialize word list
    map<string, size_t> wordCount; 
    for (string word; cin >> word && word != "*!"; /* */) {
        ++wordCount[word]; 
    }  
    // iterate through map wordCount
    // output infomation
    for (const auto &elem : wordCount) {
        cout << elem.first << " -> " << elem.second; 
        cout << (elem.second > 1) ? " times. " : " time. "; 
        cout << endl;  
    }
}

void UseSet() {
    // initialization
    const size_t CNT_VPT = 3; 
    map<string, size_t> wordCount; 
    set<string> highFrequency; 
    // initialize word list
    for (string word; cin >> word && word != "*!"; /* */) {
        ++wordCount[word]; 
    }
    // iterate through map wordCount
    // insert high frequency words to set highFrequency
    for (const auto &elem : wordCount) {
        if (elem.second > CNT_VPT) highFrequency.insert(elem.first); 
    }
    // iterate through map wordCount
    // output high frequency words
    for (const auto &elem : wordCount) {
        if (highFrequency.find(elem.first) == highFrequency.end()) continue; 
        cout << elem.first << " -> " << elem.second; 
        cout << (elem.second > 1) ? " times. " : " time. "; 
        cout << endl;  
    }
}

void UseMultiset() { 
    // initialize a vector<int>
    // 0, 0, 1, 1, 2, 2, ... , 9, 9 
    vector<int> ivec; 
    for (vector<int>::size_type i = 0; i < 10; ++i) {
        ivec.push_back(i); 
        ivec.push_back(i); 
    }
    // initialize through iterator
    set<int> iset(ivec.cbegin(), ivec.cend()); 
    multiset<int> miset(ivec.cbegin(), ivec.cend()); 
    // output size information
    // - the key word must be unique in a map or a set
    // - the key word can be recurring in a multimap or a multiset
    cout << "The size of vector is " << ivec.size() << ". " << endl; 
    cout << "The size of set is " << iset.size() << ". " << endl; 
    cout << "The size of multiset is " << miset.size() << ". " << endl; 
}

void UseMapIterator() {
    map<string, size_t> m; 
    for (map<string, size_t>::const_iterator iter = m.cbegin(); iter != m.cend(); ++iter) {
        cout << (*iter).first << " " << (*iter).second << endl; 
    }
}

void AddElementForSet() {
    // initialization
    vector<int> iv1 {
        2, 4, 6, 8, 
        2, 4, 6, 8, 
        2, 4, 6, 8, 
        2, 4, 6, 8, 
    }; 
    vector<int> iv2 {
        1, 3, 5, 7, 
        1, 3, 5, 7, 
        1, 3, 5, 7, 
        1, 3, 5, 7, 
    }; 
    set<int> is; 

    is.insert(iv1.cbegin(), iv2.cend()); 
    is.insert({2, 4, 6, 8}); 
    cout << "The size of vector iv1 is " << iv1.size() << ". " << endl; 
    cout << "The size of set is is " << is.size() << ". " << endl; 

    is.insert(iv2.cbegin(), iv2.cend()); 
    is.insert({1, 3, 5, 7}); 
    cout << "The size of vector iv2 is " << iv2.size() << ". " << endl; 
    cout << "The size of set is is " << is.size() << ". " << endl; 
    
}

void AddElementForMap() {

    map<string, size_t> m; 

    string word; 
    size_t cnt;  
    while (cin >> word && cin >> cnt) {
        // four ways to insert pair to a map
        m.insert({word, cnt}); 
        m.insert(make_pair(word, cnt)); 
        m.insert(pair<string, size_t>(word, cnt)); 
        m.insert(map<string, size_t>::value_type(word, cnt)); 
    }

}

void UseInsertReturnValue() {
    map<string, size_t> counts; 
    for (string word; cin >> word && word != "*!"; /* */) {
        pair<map<string, size_t>::iterator, bool> ret = counts.insert({word, 1}); 
        if (!ret.second) ++ret.first->second; 
    }
}

int main() {
    return 0; 
}