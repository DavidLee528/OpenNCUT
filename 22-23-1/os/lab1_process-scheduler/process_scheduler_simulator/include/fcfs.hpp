#ifndef _FCFS_HPP_
#define _FCFS_HPP_ 1

#include "sim.hpp"

class Sim_fcfs: public Sim {
public:
    Sim_fcfs(size_t _process_number, const std::vector<Process> &_processes) {
        process_number = _process_number; 
        processes = _processes; 
    }

    void simulate(); 
}; 

#endif /* _FCFS_HPP_ */