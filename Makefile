CFLAGS = -Wall -Wextra -Werror
BUILD_DIR = build/
INCLUDE_DIR = ./include
SRC_DIR = src/
TESTS_DIR = tests/
#GTEST_PATH=/usr/src/googletest/build/lib/
CC = gcc
CXX = g++


all: ${BUILD_DIR}main.o  ${BUILD_DIR}stack.o  ${BUILD_DIR}tests.o 
	@echo "Linking project..."	
	${CXX} -pthread ${BUILD_DIR}*.o -lgtest -o ${BUILD_DIR}stack

${BUILD_DIR}main.o:  ${TESTS_DIR}main.cpp
	@mkdir -p ${BUILD_DIR}
	${CXX} -c  ${TESTS_DIR}main.cpp    ${CFLAGS} -I${INCLUDE_DIR} -o ${BUILD_DIR}main.o

${BUILD_DIR}tests.o: ${TESTS_DIR}tests.cpp 
	@mkdir -p ${BUILD_DIR}
	${CXX} -c  ${TESTS_DIR}tests.cpp ${CFLAGS} -I${INCLUDE_DIR} -o ${BUILD_DIR}tests.o

${BUILD_DIR}stack.o: ${SRC_DIR}stack.c 
	@mkdir -p ${BUILD_DIR}
	${CC} -c  ${SRC_DIR}stack.c ${CFLAGS} -I${INCLUDE_DIR} -o ${BUILD_DIR}stack.o

