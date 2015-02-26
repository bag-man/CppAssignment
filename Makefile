#src=src for main project. Nice to make in src folder while developing
src=.
bin=../bin

main: $(src)/*.cpp $(src)/*.h 
	g++ $(src)/main.cpp -o $(bin)/main -Wall

clean:
	rm $(bin)/*

test: $(bin)/main
	clear
	g++ $(src)/main.cpp -o $(bin)/main -Wall
	./$(bin)/main
