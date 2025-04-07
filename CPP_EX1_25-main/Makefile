#yaeldorani@gmail.com

# Compiler
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++11 -g

# Source and object files
SRCS = main.cpp Graph.cpp Node.cpp Algorithms.cpp Queue.cpp Stack.cpp 
OBJS = main.o Graph.o Node.o Queue.o Stack.o Algorithms.o

# Output binary
TARGET = my_program

# Default rule (build the executable)
all: $(TARGET)

# Linking the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp Graph.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Graph.o: Graph.cpp Graph.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp -o Node.o

Algorithms.o: Algorithms.cpp Algorithms.hpp Graph.hpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp -o Algorithms.o

Queue.o: Queue.cpp Queue.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Queue.cpp -o Queue.o

Stack.o: Stack.cpp Stack.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Stack.cpp -o Stack.o


# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
