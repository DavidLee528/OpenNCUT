#ifndef _HRRH_HPP_
#define _HRRN_HPP_ 1

#include "sim.hpp"
#include <map>

class Sim_hrrn: public Sim {
public: 
    Sim_hrrn(size_t _process_number, const std::vector<Process> &_processes) {
        process_number = _process_number; 
        processes = _processes; 
    }

    void simulate(); 
private: 
    // response ratio = (time_wait + time_burst) / time_burst >= 1
    double response_ratio(unsigned long time_arrive, unsigned long time_now, unsigned long time_burst) const {
        return (double)(time_now - time_arrive + time_burst) / time_burst; 
    }
}; 

#endif /* _HRRN_HPP_ */