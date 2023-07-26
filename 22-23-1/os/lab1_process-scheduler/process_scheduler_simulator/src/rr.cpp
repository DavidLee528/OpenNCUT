#include "rr.hpp"

bool in_rq(const unsigned long &pid, std::queue<Process> rq) {
    while (!rq.empty()) {
        if (rq.front().get_pid() == pid) return true; 
        rq.pop(); 
    }
    return false; 
}

void push_arrived_processes(size_t time, const std::vector<Process> &processes, std::queue<Process> &rq, size_t &idx) {
    for (const auto &elem : processes) {
        if (!elem.is_finished() && elem.get_arrival_time() <= time && !in_rq(elem.get_pid(), rq)) {
            rq.push(elem); 
            ++idx; 
        }
    }
}
Process tmp{}; 
int consume_time(size_t &time, size_t quantum, std::queue<Process> &rq, size_t &remain_process_cnt, 
    std::map<unsigned long, std::vector<std::pair<unsigned long, unsigned long>>> &run_time_data, 
    std::vector<Process> &processes, size_t &idx) {
    // current process could be done within a quantum
    if (rq.front().get_remain_time() <= quantum) {
        tmp = rq.front(); 
        run_time_data[tmp.get_pid()].push_back(std::make_pair(time, time + tmp.get_remain_time())); 
        time += tmp.get_remain_time(); 
        tmp.update_remain_time(0); 
        rq.pop(); 
        --remain_process_cnt; 
        *std::find(processes.begin(), processes.end(), tmp) = tmp; 
    } else {
        // current process need more than one quantum
        tmp = rq.front(); 
        run_time_data[tmp.get_pid()].push_back(std::make_pair(time, time + quantum)); 
        time += quantum; 
        tmp.update_remain_time(tmp.get_remain_time() - quantum); 
        rq.pop(); 
        rq.push(tmp); 
        *std::find(processes.begin(), processes.end(), tmp) = tmp; 
        return rq.size() - 1;  
    }
    return -1; 
}

void Sim_rr::simulate() {
    // sort according arrival time
    // simulate real process schedule
    std::sort(processes.begin(), processes.end(), [](const Process &lhs, const Process &rhs) {
        return lhs.get_arrival_time() < rhs.get_arrival_time(); 
    }); 

    size_t total_turnaround_time {0}; 
    size_t total_waiting_time {0}; 
    size_t total_response_time {0}; 

    size_t time {this->processes.at(0).get_arrival_time()}; 
    std::vector<Process>::size_type idx {0};    // when idx reach size, all processes ready or end
    std::queue<Process> rq {}; 
    std::vector<Process>::size_type remain_process_cnt {processes.size()}; // decrease when finish a process

    push_arrived_processes(time, processes, rq, idx); 
    
    // simulate all processes
    while (remain_process_cnt) {
        
        int flag = consume_time(time, this->quantum, rq, remain_process_cnt, run_time_data, processes, idx); 
        if (idx < processes.size()) push_arrived_processes(time, processes, rq, idx); 
        
        std::queue<Process>::size_type after {rq.size()}; 
        if (flag == -1) continue; 


        std::vector<Process> tmp {}; 
        while (!rq.empty()) {
            tmp.push_back(rq.front()); 
            rq.pop(); 
        }
        Process p = tmp.at(flag); 
        for (size_t i = flag; i + 1 < after; ++i) {
            tmp.at(i) = tmp.at(i + 1); 
        }
        tmp.at(tmp.size() - 1) = p; 

        for (const auto &elem : tmp) {
            rq.push(elem); 
        }
    }
}

void Sim_rr::show() {
    for (std::map<unsigned long, std::vector<std::pair<unsigned long, unsigned long>>>::const_iterator iter = run_time_data.cbegin(); iter != run_time_data.cend(); ++iter) {
        std::cout << (*iter).first << ": "; 
        for (std::vector<std::pair<unsigned long, unsigned long>>::const_iterator viter = (*iter).second.cbegin(); viter != (*iter).second.cend(); ++viter) {
            std::cout << (*viter).first << "->" << (*viter).second << " "; 
        }
        std::cout << std::endl; 
    }
    std::cout << "<end_simulate>" << std::endl; 

    double avg_turnaround_time {0.0}; 
    double avg_wturnaround_time {0.0}; 
    double avg_waiting_time {0.0}; 
    double avg_response_time {0.0}; 
    std::cout << "pid\t" << "arrive\t" << "burst\t" << "start\t" << "end\t" << "turna\t" << "wturna\t" << "resp\t" << std::endl; 
    size_t cnt {0}; 
    for (std::map<unsigned long, std::vector<std::pair<unsigned long, unsigned long>>>::const_iterator iter = run_time_data.cbegin(); iter != run_time_data.cend(); ++iter) {
        size_t arrival_time {processes.at(cnt).get_arrival_time()}; 
        size_t start_time {(*iter).second.at(0).first}; 
        size_t end_time {(*iter).second.at((*iter).second.size() - 1).second}; 
        size_t burst_time {0}; 
        for (std::vector<std::pair<unsigned long, unsigned long>>::const_iterator viter = (*iter).second.cbegin(); viter != (*iter).second.cend(); ++viter) {
            burst_time += ( (*viter).second - (*viter).first ); 
        }
        size_t turnaround_time {end_time - arrival_time}; 
        double w_turnaround_time {static_cast<double>(turnaround_time) / burst_time}; 
        size_t response_time {start_time - arrival_time}; 

        avg_turnaround_time += static_cast<double>(turnaround_time); 
        avg_wturnaround_time += static_cast<double>(w_turnaround_time); 
        avg_response_time += static_cast<double>(response_time); 

        std::cout << (*iter).first << "\t" << arrival_time << "\t" << burst_time << "\t" << start_time << "\t" << end_time << "\t" << turnaround_time << "\t" << w_turnaround_time << "\t" << response_time << std::endl; 
        ++cnt; 
    }

    std::cout << "avg_turnaround_time:\t" << avg_turnaround_time / run_time_data.size() << std::endl; 
    std::cout << "avg_wturnaround_time:\t" << avg_wturnaround_time / run_time_data.size() << std::endl; 
    std::cout << "avg_response_time:\t"  << avg_response_time / run_time_data.size() << std::endl; 
}

void Sim_rr::gantt() { // output: (pid, start_time, end_time, arrival_time)
    for (std::map<unsigned long, std::vector<std::pair<unsigned long, unsigned long>>>::const_iterator iter = run_time_data.cbegin(); iter != run_time_data.cend(); ++iter) {
        for (std::vector<std::pair<unsigned long, unsigned long>>::const_iterator viter = (*iter).second.cbegin(); viter != (*iter).second.cend(); ++viter) {
            std::cout << "(" << (*iter).first << "," << (*viter).first << "," << (*viter).second << "," << (*std::find(processes.begin(), processes.end(), Process((*iter).first))).get_arrival_time() << ")" << std::endl; 
        }
    }
    std::cout << "<end_simulate>" << std::endl; 
}