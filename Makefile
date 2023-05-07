CXX = g++
CXXFLAGS = -g -std=c++20 -Werror -Wall -Wextra -Wpedantic -Wformat -Wmissing-include-dirs -Wuninitialized -Wunreachable-code -Wshadow -Wconversion -Wsign-conversion -Wmissing-declarations -Wredundant-decls -Winit-self -Wswitch-default -Wfloat-equal -Wundef -Wunused-parameter

visuals:
	$(CXX) $(CXXFLAGS) -o test_visuals term.cpp ntest.cpp test_visuals.cpp
	./test_visuals

logic:
	$(CXX) $(CXXFLAGS) -o test_logic term.cpp ntest.cpp test_logic.cpp
	./test_logic
