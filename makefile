all:
	g++ main.cpp "Calculator Components/*.cpp" -o main

test:
	g++ teste.cpp "Calculator Components/CPULucio.cpp" && clear && ./a.exe
