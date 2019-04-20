all: compile

compile:
	g++ */*.cpp *.cpp */*/*.cpp -o main

clean:
	rm -rf main functions