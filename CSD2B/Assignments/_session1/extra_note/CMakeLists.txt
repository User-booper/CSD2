cmake_minimum_required(VERSION 3.10)
project(note)

add_executable(note main_extra_note.cpp)
set_property(TARGET note PROPERTY CXX_STANDARD 20)
