cmake_minimum_required(VERSION 3.13)
project(DonorList)
file (GLOB SOURCES
	headers/*.h
	source/*.cpp
)
add_executable(DonorList ${SOURCES})
