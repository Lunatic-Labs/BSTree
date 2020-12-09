CXX = g++
CXXFlags = -Wall -g


main: main.o BSTree.o BSTreeNode.o
	$(CXX)$(CXXFLAGS) -o main main.o BSTree.o BSTreeNode.o

main.o: main.cpp BSTree.hpp BSTreeNode.hpp IBSTree.h
	$(CXX)$(CXXFLAGS) -c main.cpp



BSTreeNode.o: BSTreeNode.cpp BSTree.hpp BSTreeNode.hpp
	$(CXX)$(CXXFLAGS) -c BSTreeNode.cpp	
BSTree.o: BSTree.cpp BSTree.hpp BSTreeNode.hpp
	$(CXX)$(CXXFLAGS) -c BSTree.cpp

