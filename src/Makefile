src=.
bin=../bin
inc=../include

main: $(src)/*.cpp $(inc)/*.h
	g++ $(src)/*.cpp -o $(bin)/main -Wall -I $(inc) -std=c++11

clean:
	rm $(bin)/*

test: $(bin)/main
	./$(bin)/main --config=../configs --step

memcheck: $(bin)/main
	valgrind --leak-check=full ./$(bin)/main
