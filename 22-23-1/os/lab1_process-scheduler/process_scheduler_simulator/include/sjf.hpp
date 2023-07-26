#ifndef _SJF_HPP_
#define _SJF_HPP_ 1

#include "sim.hpp"

class Sim_sjf: public Sim {
public: 
    Sim_sjf(size_t _process_number, const std::vector<Process> &_processes) {
        process_number = _process_number; 
        processes = _processes; 
    }

    void simulate(); 
}; 

#endif /* _SJF_HPP_ */