#include "sjf.hpp"

void Sim_sjf::simulate() {
    // sort according arrival time
    // simulate real process schedule
    std::sort(processes.begin(), processes.end(), [](const Process &lhs, const Process &rhs) {
        return lhs.get_arrival_time() < rhs.get_arrival_time(); 
    }); 

    size_t cnt = 0; 
    std::vector<Process> arrived { }; 
    for (size_t time = processes.at(0).get_arrival_time(); cnt < processes.size(); ++time) {
        // clear the arrived-but-not-finished array
        arrived.clear(); 
        // get all arrived-but-not-finished processes
        for (std::vector<Process>::const_iterator iter = processes.cbegin(); iter != processes.cend(); ++iter) {
            if (!(*iter).is_finished() && (*iter).get_arrival_time() <= time) arrived.push_back(*iter); 
        }
        if (arrived.empty()) continue; 

        // shortest job first
        Process &p = *std::find(processes.begin(), processes.end(), 
                                *std::min_element(arrived.begin(), arrived.end(), 
                                [](const Process &lhs, const Process &rhs) 
                                { return lhs.get_burst_time() < rhs.get_burst_time(); })); 

        size_t start_time = time;               // log start time
        time += p.get_burst_time() - 1;         // each loop ++time, so here minus 1
        p.set_time_data_when_finish(
            start_time, 
            time + 1, 
            time + 1 - p.get_arrival_time(), 
            ((double)1 / p.get_burst_time()) * (time + 1 - p.get_arrival_time()), 
            time + 1 - p.get_arrival_time() - p.get_burst_time()
        ); 
        ++cnt;                                  // when cnt reach processes.size(), the loop ends
        continue;                               // start next loop
    }
}
