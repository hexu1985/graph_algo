
RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -DUSE_DENSE_GRAPH #-DUSE_SPARSE_MAULTI_GRAPH_ORIGIN 
INCLUDES = -I../include -I../test
LDFLAGS =
LDPATH =

SOURCES = $(shell ls *.cpp)
PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
