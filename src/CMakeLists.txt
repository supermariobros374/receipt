cmake_minimum_required(VERSION 3.8)
include_directories(${check_receipt_source_dir}/lib)
link_directories(${check_receipt_bin_dir}/lib)

add_executable(receipt main.cpp)
target_link_libraries(receipt ${check_receipt_source_dir}/lib)
