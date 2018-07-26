CXX = g++
CXXFLAGS = -O3 -std=c++1z
LINKFLAGS = -lm

SRCS1 =\
	Fraction.cpp\
	trie.cpp\
	trie_ex.cpp\
	Polynomial.cpp\
	Polynomial_lhm.cpp\
	Polynomial_ex.cpp\
	Initialdata.cpp\
	Rule.cpp\
	longitude.cpp\
	Extract.cpp\
	Extract_lhm.cpp\
	Extract_ex.cpp\

SRCS2 =\
	main.cpp\

OBJS1 = $(SRCS1:%.cpp=%.o)
OBJS2 = $(SRCS2:%.cpp=%.o)

all: milnor

milnor:$(OBJS1) $(OBJS2)
	$(CXX) $(CXXFLAGS) $(OBJS1) $(OBJS2) $(LINKFLAGS) -o milnor

debug:
	make all CVXXFLAGS="-ggdb -W -Wall -pedantic"

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< 

clean:
	rm -f milnor *.o *~ milnor

