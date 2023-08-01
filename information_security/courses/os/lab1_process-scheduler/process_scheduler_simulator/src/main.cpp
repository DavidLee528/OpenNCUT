#include "main.hpp"

int main(int argc, const char **argv) {

    std::cout << "NCUT OS Lab 1: Process Scheduler Simulator (author: " << ASCII_COLOR_GREEN << "Tianhao Lee" << ASCII_COLOR_END << ", InfoSec20-2, 20101110201) " << std::endl; 

    bool gantt_mode = false; 
    if (argc == 2) gantt_mode = true; 
    start_simulate(gantt_mode); 

    return 0; 
}

void start_simulate(bool gantt_mode) {
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

    std::cout << ASCII_COLOR_GREEN << "First Come First Serve" << ASCII_COLOR_END << std::endl; 
    Sim_fcfs fcfs(n, pa); 
    fcfs.simulate(); 
    if (!gantt_mode) fcfs.show(); 
    else fcfs.gantt(); 

    std::cout << ASCII_COLOR_GREEN << "Shortest Job First" << ASCII_COLOR_END << std::endl; 
    Sim_sjf sjf(n, pa); 
    sjf.simulate(); 
    if (!gantt_mode) sjf.show(); 
    else sjf.gantt(); 

    std::cout << ASCII_COLOR_GREEN << "Highest Response-Ratio Next" << ASCII_COLOR_END << std::endl; 
    Sim_hrrn hrrn(n, pa); 
    hrrn.simulate(); 
    if (!gantt_mode) hrrn.show(); 
    else hrrn.gantt(); 

    std::cout << ASCII_COLOR_GREEN << "Round-Robin" << ASCII_COLOR_END << std::endl; 
    Sim_rr rr(n, pa); 
    rr.simulate(); 
    if (!gantt_mode) rr.show(); 
    else rr.gantt(); 
    
    
}