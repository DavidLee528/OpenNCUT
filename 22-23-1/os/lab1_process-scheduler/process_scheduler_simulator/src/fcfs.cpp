#include "fcfs.hpp"

void Sim_fcfs::simulate() {
    // sort according arrival time
    // first come first serve
    std::sort(processes.begin(), processes.end(), [](const Process &lhs, const Process &rhs) {
        return lhs.get_arrival_time() < rhs.get_arrival_time(); 
    }); 

    // iterate processes array (sorted by arrival time)
    // start from time moment 0
    size_t time = processes.at(0).get_arrival_time(); 

    for (std::vector<Process>::iterator iter = processes.begin(); iter != processes.end(); ++iter) {
        // serve current process
        if (!(*iter).is_finished() && (*iter).get_arrival_time() <= time) {
            // log start time
            size_t start_time = time; 

            // current process consume time 
            time += (*iter).get_burst_time(); 

            // set time datas when current process is finish
            unsigned long arrival_time = (*iter).get_arrival_time(); 
            unsigned long burst_time = (*iter).get_burst_time(); 
            (*iter).set_time_data_when_finish(
                start_time,                                         // start execute time
                time,                                               // end execute time
                time - arrival_time,                                // turnaround time
                ((double)1 / burst_time) * (time - arrival_time),   // weighted turnaround time
                time - arrival_time - burst_time                    // waiting time
            ); 
            continue; 
        }
        ++time; 
    }
}