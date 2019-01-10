cmake_minimum_required (VERSION 2.8)

project (Enigma)

aux_source_directory(. DIR_SRCS)

add_executable(Enigma ${DIR_SRCS})