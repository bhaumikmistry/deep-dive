#include <chrono>
#include <string>
#include <iostream>

class BigONotation
{
public:
    int * theArray;
    int arraySize;
    int itemsInArray;
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;

    BigONotation(int size)
    {
        arraySize = size;
        theArray = new int[size];
    }

    ~BigONotation(){}

    void generateRandomArray()
    {
        for(int i=0;i<arraySize;i++)
        {
            theArray[i] = (int)(rand()*1000)+10;
        }
        itemsInArray = arraySize-1;
    }


    /* O(1) Runs at the same time no matter how long the array is */
    void addItemToArray(int newItem)
    {
        theArray[itemsInArray++] = newItem;
    }

    /* O(N) linear Search*/
    void linearSearchForValue(int value)
    {
        bool valueInArray = false;
        std::string indexsWithValue = "";

        begin  = std::chrono::steady_clock::now();

        for(int i =0;i<arraySize;i++)
        {
            if(theArray[i]==value)
            {
                valueInArray = true;
                indexsWithValue += std::to_string(i) + " ";
            }
        }


        end = std::chrono::steady_clock::now();

        std::cout   << "Time Taken by LinearSearchForValue = " 
                    << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() 
                    << "[µs] " ;
        std::string val = (valueInArray)? "True" : "False" ;
        std::cout << "Found? " << val << std::endl;
    }

};