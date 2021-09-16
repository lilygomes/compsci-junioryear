cmake_minimum_required(VERSION 3.13)
project(MatrixClass)
file (GLOB SOURCES
	headers/*.h
	source/*.cpp
)
add_executable(MatrixClass ${SOURCES})
