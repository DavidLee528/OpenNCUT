include_directories(${PROJECT_SOURCE_DIR}/include)

add_compile_options(-g)

add_executable(process_scheduler_simulator process.cpp fcfs.cpp sjf.cpp hrrn.cpp rr.cpp main.cpp)