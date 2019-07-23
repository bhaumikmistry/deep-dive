#include <iostream>
#include "BigONotation.cpp"

int main(int argc, char **argv){

    std::cout << "main()" << std::endl;

    BigONotation bigON1(10000);
    bigON1.generateRandomArray();
    bigON1.linearSearchForValue(123);

    BigONotation bigON2(15000);
    bigON2.generateRandomArray();
    bigON2.linearSearchForValue(123);

    BigONotation bigON3(30000);
    bigON3.generateRandomArray();
    bigON3.linearSearchForValue(123);

    BigONotation bigON4(70000);
    bigON4.generateRandomArray();
    bigON4.linearSearchForValue(123);

	return 0;
	
}