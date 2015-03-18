src=src
bin=bin
inc=include

main: $(src)/*.cpp $(inc)/*.h 
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I $(inc) -std=c++0x

clean:
	rm $(bin)/*

test: $(bin)/main
	./$(bin)/main --step

memcheck: $(bin)/main
	valgrind --leak-check=full ./$(bin)/main
