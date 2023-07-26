#ifndef _RR_HPP_
#define _RR_HPP_ 1

#include "sim.hpp"
#include <queue>
#include <map>

class Sim_rr: public Sim {
public: 
    Sim_rr(size_t _process_number, const std::vector<Process> &_processes, size_t _quantum = 2) {
        process_number = _process_number; 
        processes = _processes; 
        quantum = _quantum; 
    }

    void simulate(); 
    void show(); 
    void gantt(); 
private: 
    size_t quantum;         // the length of time slice
    std::map<unsigned long, std::vector<std::pair<unsigned long, unsigned long>>> run_time_data { }; // pid -> vector<start_time, end_time>
}; 

#endif /* _RR_HPP_ */