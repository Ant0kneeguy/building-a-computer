cmake_minimum_required(VERSION 3.1)
project(Computer VERSION 1.0
				DESCRIPTION "Building a computer inside my computer"
				LANGUAGES C)

add_executable(main main.c)

add_library(const STATIC libconst/constant.c)
target_include_directories(const PUBLIC libconst)

add_library(wire STATIC libwire/wire.c)
target_include_directories(wire PUBLIC libwire)

add_library(trans STATIC libtrans/transistor.c)
target_include_directories(trans PUBLIC libtrans)

add_library(gate STATIC libgate/notGate.c libgate/andGate.c libgate/orGate.c
			libgate/nandGate.c libgate/norGate.c libgate/xorGate.c)
target_include_directories(gate PUBLIC libgate)

target_link_libraries(main PUBLIC const wire trans gate)
