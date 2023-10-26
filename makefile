all:
	g++ main.cpp "Calculator Components/*.cpp" -o main

test:
	g++ main.cpp **/*.cpp" -o main 
