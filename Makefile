VERSION = 1
mmvec = ./mmvec
mmnovec = ./mmnovec
CXX = g++
FLAGS = -Wall -O -g
FILES = $(mmvec) $(mmnovec)

all: $(FILES)

mmvec:
	$(CXX) $(FLAGS) -Wall -W -Werror -O2 -ftree-vectorize -o mmvec mm.cpp

mmnovec:
	$(CXX) $(FLAGS) -Wall -W -Werror -o mmnovec mm.cpp

clean:
	rm -f $(FILES) *.o
