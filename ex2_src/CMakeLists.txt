add_compile_options(-std=c++11)

file (GLOB SRCS *.cpp *.h)

add_executable ( Ex2 ${SRCS})