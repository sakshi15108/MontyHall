
all: MHprob

CXXFLAGS:=-g -O3 -std=c++17

MHprob:./sim_MH.cpp
	g++ -o sim_MH ./sim_MH.cpp $(CXXFLAGS)

clean:
	@rm -f ./sim_MH
