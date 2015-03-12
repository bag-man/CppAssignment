src=.
bin=../bin
inc=../include

main: $(src)/*.cpp $(inc)/*.h 
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I $(inc) -std=c++11

clean:
	rm $(bin)/*

test: $(bin)/main
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I $(inc) -std=c++11
	./$(bin)/main

memcheck: $(bin)/main
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I $(inc) -std=c++11
	valgrind --leak-check=full ./$(bin)/main
