find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
include_directories(${PROJECT_SOURCE_DIR}/include)
add_compile_options(-g)

add_executable(test_fcfs test_fcfs.cpp ${PROJECT_SOURCE_DIR}/src/fcfs.cpp ${PROJECT_SOURCE_DIR}/src/process.cpp) 
add_executable(test_sjf test_sjf.cpp ${PROJECT_SOURCE_DIR}/src/sjf.cpp ${PROJECT_SOURCE_DIR}/src/process.cpp) 
add_executable(test_hrrn test_hrrn.cpp ${PROJECT_SOURCE_DIR}/src/hrrn.cpp ${PROJECT_SOURCE_DIR}/src/process.cpp) 
add_executable(test_rr test_rr.cpp ${PROJECT_SOURCE_DIR}/src/rr.cpp ${PROJECT_SOURCE_DIR}/src/process.cpp) 

target_link_libraries(test_fcfs
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
target_link_libraries(test_sjf
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
target_link_libraries(test_hrrn
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
target_link_libraries(test_rr
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )

enable_testing()
add_test(FCFS_TEST test_fcfs)
add_test(SJF_TEST test_sjf)
add_test(HRRN_TEST test_hrrn)
add_test(RR_TEST test_rr)