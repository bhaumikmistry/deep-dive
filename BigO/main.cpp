#include <iostream>
#include "BigONotation.cpp"

int main(int argc, char **argv){

    std::cout << "main()" << std::endl;

    BigONotation bigON1(10000);
    bigON1.generateRandomArray();

    BigONotation bigON2(15000);
    bigON2.generateRandomArray();

    BigONotation bigON3(30000);
    bigON3.generateRandomArray();

    BigONotation bigON4(70000);
    bigON4.generateRandomArray();

    bigON1.BubbleSort();
    bigON2.BubbleSort();
    bigON3.BubbleSort();
    bigON4.BubbleSort();
    

    // bigON1.linearSearchForValue(123);
    // bigON2.linearSearchForValue(123);
    // bigON3.linearSearchForValue(123);
    // bigON4.linearSearchForValue(123);

	return 0;
	
}