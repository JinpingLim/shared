all: lab8 lab8Test

lab8Test: lab8Test.o node.o
	g++ -Wall -Werror -std=c++17 -o lab8Test lab8Test.o node.o

lab8: lab8.o node.o
	g++ -Wall -Werror -std=c++17 -o lab8 lab8.o node.o

lab8.o: lab8.cpp
	g++ -Wall -Werror -std=c++17 -c lab8.cpp

lab8Test.o: lab8Test.cpp
	g++ -Wall -Werror -std=c++17 -c lab8Test.cpp

node.o: node.cpp	
	g++ -Wall -Werror -std=c++17 -c node.cpp

clean:
	rm -f lab8 lab8Test *.o