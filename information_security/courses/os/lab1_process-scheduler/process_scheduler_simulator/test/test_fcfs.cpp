#define BOOST_TEST_MODULE FCFS_TEST
#include <boost/test/unit_test.hpp>
#include "test_case_path.hpp"

#include "fcfs.hpp"
#include <fstream>
#include <sstream>
#include <string>

BOOST_AUTO_TEST_CASE(PassTest) {
    // read test case file
    std::ifstream test_case; 
    test_case.open(TEST_CASE_PATH, std::ios::in); 
    if (!test_case.is_open()) throw "fail to load test_case.txt"; 

    // how many processes in total
    size_t n; 
    test_case >> n; 
    
    // processes array
    std::vector<Process> pa; 

    // input every process information
    for (size_t i = 0; i < n; ++i) {
        Process p; 
        test_case >> p;  
        pa.push_back(p); 
    }

    // close test case file
    test_case.close(); 

    Sim_fcfs s(n, pa); 
    s.simulate(); 
    s.show(); 


}


