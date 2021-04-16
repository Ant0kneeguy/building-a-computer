cmake_minimum_required(VERSION 3.1)
project(Computer VERSION 1.0
				DESCRIPTION "Building a computer inside my computer"
				LANGUAGES C)

add_executable(main main.c)

add_library(const STATIC constants/constant.c)
target_include_directories(const PUBLIC constants)

add_library(wire STATIC wire/wire.c)
target_include_directories(wire PUBLIC wire)

add_library(trans STATIC transistor/transistor.c)
target_include_directories(trans PUBLIC transistor)

add_library(gate STATIC logic_gates/notGate.c logic_gates/andGate.c
			logic_gates/orGate.c logic_gates/nandGate.c logic_gates/norGate.c 
			logic_gates/xorGate.c)
target_include_directories(gate PUBLIC logic_gates)

target_link_libraries(main PUBLIC const wire trans gate)
