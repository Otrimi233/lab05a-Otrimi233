CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES = test

all: ${BINARIES}

test: lab05Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o