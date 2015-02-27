src=src
bin=bin
inc=include

main: $(src)/*.cpp $(inc)/*.h 
	g++ $(src)/main.cpp -o $(bin)/main -Wall

clean:
	rm $(bin)/*

test: $(bin)/main
	clear
	g++ $(src)/main.cpp -o $(bin)/main -Wall
	./$(bin)/main
