clear
g++ -c Arrays.cpp -o Arrays.o
g++ -c main.cpp -o main.o
g++ -o main main.o Arrays.o
./main