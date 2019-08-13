clear
g++ -c LinkedList.cpp -o ll.o
g++ -c main.cpp -o main.o
g++ -o main main.o ll.o
./main