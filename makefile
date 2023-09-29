all:
	g++ -o components -I Calculator Components "Calculator Components/Display.cpp"
	g++ -o main main.cpp -I "Calculator Components/components"
