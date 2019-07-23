clear
g++ -c BigONotation.cpp -o BigONotation.o
g++ -c main.cpp -o main.o
g++ -o main main.o BigONotation.o
./main