files= program1.cpp program2.cpp program3.cpp

all: $(files)
	g++ -o program1 program1.cpp -std=c++14
	g++ -o program2 program2.cpp -std=c++14
	g++ -o program3 program3.cpp -std=c++14

clean:
	rm -rf output*.txt

run: all
	./program1 filex.txt filey.txt output1.txt
	./program2 filex.txt filey.txt output2.txt
	./program3 filex.txt filey.txt output3.txt

winclean:
	del program*.exe
	del output*.txt