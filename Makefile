src=src
bin=bin
inc=include

main: $(src)/*.cpp $(inc)/*.h 
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I include/ -std=c++11

clean:
	rm $(bin)/*

test: $(bin)/main
	clear
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I include/ -std=c++11
	./$(bin)/main
